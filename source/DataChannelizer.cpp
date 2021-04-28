//
// Created by willy on 4/19/21.
//

#include "DataChannelizer.h"

// Knows how to insert and extract bits from Frame object.
DataChannelizer::DataChannelizer(
    const char *title,
    const char *label,
    const char *tooltip,
    bool optional,
    bool useData2,
    U32 bitsWide,
    U32 shift) :
    Channelizer(title, label, tooltip, optional),
    mUseData2(useData2),
    mBitsWide(bitsWide),
    mShift(shift) {
  if (bitsWide < 64) {
    mMask = (1 << bitsWide) - 1;
  } else {
    mMask = 0xFFFFffffFFFFffff;
  }
}

void DataChannelizer::getDescriptiveString(Frame &frame, DisplayBase display_base, char *result_string,
                                           U32 result_string_max_length) const {
  AnalyzerHelpers::GetNumberString(extractDataValue(frame), display_base, mBitsWide, result_string,
                                   result_string_max_length);
}

U64 DataChannelizer::extractDataValue(const Frame &frame) const {
  U64 data_value = ((mUseData2 ? frame.mData2 : frame.mData1) >> mShift) & mMask;
  return data_value;
}

SignalGrabber *DataChannelizer::createSignalGrabber(Analyzer2 *analyzer) {
  AnalyzerChannelData *analyzerChannelData = analyzer->GetAnalyzerChannelData(mChannel);
  return new SignalGrabber(analyzerChannelData, mUseData2, mMask, mShift);
}

DataChannelizer::~DataChannelizer() = default;


ServoDataChannelizer::ServoDataChannelizer(const char *title, const char *label, const char *tooltip, bool optional,
                                           bool useData2, U32 bitsWide, U32 shift) : DataChannelizer(title, label,
                                                                                                     tooltip, optional,
                                                                                                     useData2, bitsWide,
                                                                                                     shift) {}

void ServoDataChannelizer::getDescriptiveString(Frame &frame, DisplayBase display_base, char *result_string,
                                                U32 result_string_max_length) const {
  if (result_string_max_length > 5)
  {
    U64 data_value = extractDataValue(frame);
    const char flags[] = "NXYZnzyx89abcdef";
    int shift = 12;
    while (shift >= 0) {
      int flag_index = (data_value >> shift) & 0x0f;
      *result_string++ = flags[flag_index];
      shift -= 4;
      result_string_max_length--;
    }
  }
  if (display_base == Decimal)
  {
    // A bit hacky but decimal is useless in this context, so allow it to be used to see ONLY the flags.
    *result_string++ = 0;
  } else {
    *result_string++ = ' ';
    AnalyzerHelpers::GetNumberString(extractDataValue(frame), display_base, mBitsWide, result_string,
                                     result_string_max_length - 5);
  }
}

ConsoleDataChannelizer::ConsoleDataChannelizer(const char *title, const char *label, const char *tooltip, bool optional,
                                               bool useData2, U32 bitsWide, U32 shift) : DataChannelizer(title, label,
                                                                                                         tooltip,
                                                                                                         optional,
                                                                                                         useData2,
                                                                                                         bitsWide,
                                                                                                         shift) {}

