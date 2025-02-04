//
// Created by willy on 4/19/21.
//

#include "MasterChannelizerManager.h"

MasterChannelizerManager::MasterChannelizerManager() = default;

MasterChannelizerManager::~MasterChannelizerManager() = default;

void
MasterChannelizerManager::addClockingChannelizer(ClockingChannelizer *clockingChannelizer, bool transferOwnership) {
  mClockingManager.addClockingChannelizer(clockingChannelizer, transferOwnership);
  mChannelizers.push_back(clockingChannelizer);
}

void MasterChannelizerManager::addDataChannelizer(DataChannelizer *dataChannelizer, bool transferOwnership) {
  mDataManager.addDataChannelizer(dataChannelizer, transferOwnership);
  mChannelizers.push_back(dataChannelizer);
}

void MasterChannelizerManager::addChannelInterfaces(ChannelizedAnalyzerSettings *settings) {
  mClockingManager.addChannelInterfaces(settings);
  mDataManager.addChannelInterfaces(settings);
}

void MasterChannelizerManager::addChannelsUnused(ChannelizedAnalyzerSettings *settings) {
  mClockingManager.addChannelsUnused(settings);
  mDataManager.addChannelsUnused(settings);
}

void MasterChannelizerManager::addChannels(ChannelizedAnalyzerSettings *settings) {
  mClockingManager.addChannels(settings);
  mDataManager.addChannels(settings);
}

void MasterChannelizerManager::setChannelsFromInterfaces() {
  mClockingManager.setChannelsFromInterfaces();
  mDataManager.setChannelsFromInterfaces();
}

void MasterChannelizerManager::setInterfacesFromChannels() {
  mClockingManager.setInterfacesFromChannels();
  mDataManager.setInterfacesFromChannels();
}


bool MasterChannelizerManager::doChannelsOverlap() {
  return Channelizer::hasOverlap(mChannelizers);
}

bool MasterChannelizerManager::hasAtLeastOneDataChannel() {
  return mDataManager.hasAtLeastOneDefinedChannel();
}

void MasterChannelizerManager::loadFromArchive(SimpleArchive &archive) {
  mClockingManager.loadFromArchive(archive);
  mDataManager.loadFromArchive(archive);
}

void MasterChannelizerManager::saveToArchive(SimpleArchive &archive) {
  mClockingManager.saveToArchive(archive);
  mDataManager.saveToArchive(archive);
}

std::string MasterChannelizerManager::dataTitles(const char *delim) {
  return mDataManager.titles(delim);
}

bool
MasterChannelizerManager::getDescriptiveString(Frame &frame, Channel &channel, DisplayBase display_base, char *result_string,
                                               U32 result_string_max_length) {
  DataChannelizer *channelizer = getDataChannelizer(channel);
  if (channelizer) {
    channelizer->getDescriptiveString(frame, display_base, result_string, result_string_max_length - 4);
    return true;
  } else { return false; }
}

DataChannelizer *MasterChannelizerManager::getDataChannelizer(Channel &channel) {
  return mDataManager.getDataChannelizer(channel);
}

std::string MasterChannelizerManager::activeDataTitles(const char *delim) {
  std::vector<Channelizer *> definedDataChannelizers = mDataManager.definedChannels();
  return Channelizer::titles(definedDataChannelizers, delim);
}

std::vector<DataChannelizer *> MasterChannelizerManager::definedDataChannels() {
  return mDataManager.definedDataChannels();
}


void MasterChannelizerManager::markDataChannelsAsBubbleWorthy(AnalyzerResults *analyzerResults) {
  mDataManager.markChannelsAsBubbleWorthy(analyzerResults);
}


