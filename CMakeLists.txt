cmake_minimum_required(VERSION 3.19)
project(DaisyAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(AnalyzerSDK)
include_directories(AnalyzerSDK/include)
include_directories(source)

add_library(DaisyAnalyzer SHARED
        AnalyzerSDK/include/Analyzer.h
        AnalyzerSDK/include/AnalyzerChannelData.h
        AnalyzerSDK/include/AnalyzerHelpers.h
        AnalyzerSDK/include/AnalyzerResults.h
        AnalyzerSDK/include/AnalyzerSettingInterface.h
        AnalyzerSDK/include/AnalyzerSettings.h
        AnalyzerSDK/include/AnalyzerTypes.h
        AnalyzerSDK/include/LogicPublicTypes.h
        AnalyzerSDK/include/SimulationChannelDescriptor.h
        source/AnalyzerChannelDataHolder.cpp
        source/AnalyzerChannelDataHolder.h
        source/BitGenerator.cpp
        source/BitGenerator.h
        source/ChannelizedAnalyzerSettings.cpp
        source/ChannelizedAnalyzerSettings.h
        source/Channelizer.cpp
        source/Channelizer.h
        source/ChannelizerManager.cpp
        source/ChannelizerManager.h
        source/ChannelizerOwner.cpp
        source/ChannelizerOwner.h
        source/Clocker.cpp
        source/Clocker.h
        source/ClockingChannelizer.cpp
        source/ClockingChannelizer.h
        source/ClockingChannelizerManager.cpp
        source/ClockingChannelizerManager.h
        source/DaisyAnalyzer.cpp
        source/DaisyAnalyzer.h
        source/DaisyAnalyzerResults.cpp
        source/DaisyAnalyzerResults.h
        source/DaisyAnalyzerSettings.cpp
        source/DaisyAnalyzerSettings.h
        source/DaisyChannelizerManager.cpp
        source/DaisyChannelizerManager.h
        source/DaisySimulationDataGenerator.cpp
        source/DaisySimulationDataGenerator.h
        source/DataChannelizer.cpp
        source/DataChannelizer.h
        source/DataChannelizerManager.cpp
        source/DataChannelizerManager.h
        source/MasterChannelizerManager.cpp
        source/MasterChannelizerManager.h
        source/SignalGrabber.cpp
        source/SignalGrabber.h
        )
#source/DaisyAnalyzer.cpp
#        source/DaisyAnalyzer.h
#        source/DaisyAnalyzerResults.cpp
#        source/DaisyAnalyzerResults.h
#        source/DaisyAnalyzerSettings.cpp
#        source/DaisyAnalyzerSettings.h
#        source/DaisySimulationDataGenerator.cpp
#        source/DaisySimulationDataGenerator.h)
