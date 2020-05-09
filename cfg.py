import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

# initialize MessageLogger and output report

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                                # replace 'myfile.root' with the source file you want to use
                                fileNames = cms.untracked.vstring(
            'file:/afs/cern.ch/work/d/ddesouza/public/Cent_filter/reMiniAOD_DATA_PAT_withCentfilter.root'
#            'file:/afs/cern.ch/work/d/ddesouza/public/Cent_filter/reMiniAOD_DATA_PAT_withoutCentfilter.root'
                )
                            )

process.demo = cms.EDAnalyzer('DemoAnalyzer',
                                srcPFcand         = cms.InputTag("packedPFCandidates"),
				trigger           = cms.InputTag("TriggerResults","","PAT")
                              )

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('test.root')
                                   )


process.p = cms.Path(process.demo)
