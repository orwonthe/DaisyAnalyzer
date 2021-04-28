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
  if (result_string_max_length > 12)
  {
    U64 data_value = extractDataValue(frame);
    const char command_flags[] = "NXYZnzyx89abcdef";
    const char status_flag[] = "_s=S";
    int command_shift = 16;
    int status_shift = 24;
    while (command_shift > 0) {
      command_shift -= 4;
      status_shift -= 2;
      int command_flag_index = (data_value >> command_shift) & 0x0f;
      int status_flag_index = (data_value >> status_shift) & 0x03;
      *result_string++ = command_flags[command_flag_index]; result_string_max_length--;
      *result_string++ = status_flag[status_flag_index]; result_string_max_length--;
      *result_string++ = ' '; result_string_max_length--;
    }
  }
  if (display_base == Decimal)
  {
    // A bit hacky but decimal is useless in this context, so allow it to be used to see ONLY the flags.
    *result_string++ = 0; result_string_max_length--;
  } else {
    AnalyzerHelpers::GetNumberString(extractDataValue(frame), display_base, mBitsWide, result_string,
                                     result_string_max_length);
  }
}

ConsoleDataChannelizer::ConsoleDataChannelizer(const char *title, const char *label, const char *tooltip, bool optional,
                                               bool useData2, U32 bitsWide, U32 shift) : DataChannelizer(title, label,
                                                                                                         tooltip,
                                                                                                         optional,
                                                                                                         useData2,
                                                                                                         bitsWide,
                                                                                                         shift) {}

