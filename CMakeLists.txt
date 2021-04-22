cmake_minimum_required(VERSION 3.19)
project(DaisyAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(AnalyzerSDK)
include_directories(AnalyzerSDK/include)
include_directories(LegacyAnalyzerSDK)
include_directories(LegacyAnalyzerSDK/include)
include_directories(source)

add_executable(DaisyAnalyzer
        AnalyzerSDK/include/Analyzer.h
        AnalyzerSDK/include/AnalyzerChannelData.h
        AnalyzerSDK/include/AnalyzerHelpers.h
        AnalyzerSDK/include/AnalyzerResults.h
        AnalyzerSDK/include/AnalyzerSettingInterface.h
        AnalyzerSDK/include/AnalyzerSettings.h
        AnalyzerSDK/include/AnalyzerTypes.h
        AnalyzerSDK/include/LogicPublicTypes.h
        AnalyzerSDK/include/SimulationChannelDescriptor.h
        LegacyAnalyzerSDK/include/Analyzer.h
        LegacyAnalyzerSDK/include/AnalyzerChannelData.h
        LegacyAnalyzerSDK/include/AnalyzerHelpers.h
        LegacyAnalyzerSDK/include/AnalyzerResults.h
        LegacyAnalyzerSDK/include/AnalyzerSettingInterface.h
        LegacyAnalyzerSDK/include/AnalyzerSettings.h
        LegacyAnalyzerSDK/include/AnalyzerTypes.h
        LegacyAnalyzerSDK/include/LogicPublicTypes.h
        LegacyAnalyzerSDK/include/SimulationChannelDescriptor.h
        source/DaisyAnalyzer.cpp
        source/DaisyAnalyzer.h
        source/DaisyAnalyzerResults.cpp
        source/DaisyAnalyzerResults.h
        source/DaisyAnalyzerSettings.cpp
        source/DaisyAnalyzerSettings.h
        source/DaisySimulationDataGenerator.cpp
        source/DaisySimulationDataGenerator.h)
