#ifndef DSHOT_ANALYZER_H
#define DSHOT_ANALYZER_H

#include <Analyzer.h>
#include "dshotAnalyzerResults.h"
#include "dshotSimulationDataGenerator.h"

class dshotAnalyzerSettings;
class ANALYZER_EXPORT dshotAnalyzer : public Analyzer
{
public:
	dshotAnalyzer();
	virtual ~dshotAnalyzer();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< dshotAnalyzerSettings > mSettings;
	std::auto_ptr< dshotAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	dshotSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //DSHOT_ANALYZER_H
