#ifndef DSHOT_SIMULATION_DATA_GENERATOR
#define DSHOT_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class dshotAnalyzerSettings;

class dshotSimulationDataGenerator
{
public:
	dshotSimulationDataGenerator();
	~dshotSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, dshotAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	dshotAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //DSHOT_SIMULATION_DATA_GENERATOR