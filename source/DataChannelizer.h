//
// Created by willy on 4/19/21.
//

#ifndef DAISY_ANALYZER_DATACHANNELIZER_H
#define DAISY_ANALYZER_DATACHANNELIZER_H

#include "Channelizer.h"
#include "SignalGrabber.h"
#include <AnalyzerResults.h>

class SignalGrabber;

class DataChannelizer : public Channelizer {
public:
  virtual ~DataChannelizer();

  DataChannelizer(const char *title, const char *label, const char *tooltip, bool optional, bool useData2,
                  U32 bitsWide, U32 shift);

  virtual void getDescriptiveString(Frame &frame, DisplayBase display_base, char *result_string, U32 result_string_max_length) const;
  SignalGrabber *createSignalGrabber(Analyzer2 *analyzer);

protected:
  bool mUseData2;
  U32 mBitsWide;
  U64 mMask;
  U32 mShift;
  U64 extractDataValue(const Frame &frame) const;
};

class ServoDataChannelizer: public DataChannelizer {
public:
  ServoDataChannelizer(const char *title, const char *label, const char *tooltip, bool optional, bool useData2,
                       U32 bitsWide, U32 shift);
  virtual void getDescriptiveString(Frame &frame, DisplayBase display_base, char *result_string, U32 result_string_max_length) const;

};

class ConsoleDataChannelizer: public DataChannelizer {
public:
  ConsoleDataChannelizer(const char *title, const char *label, const char *tooltip, bool optional, bool useData2,
                         U32 bitsWide, U32 shift);

};


#endif //DAISY_ANALYZER_DATACHANNELIZER_H
