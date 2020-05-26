import FWCore.ParameterSet.Config as cms

from RecoHI.HiCentralityAlgos.hfCoincFilter_cff import *

#---------------add centrality filters here---------------------
# make calotowers into candidates
Flag_towersAboveThreshold = cms.Path(towersAboveThreshold)
# make calotowers into candidates with threshold 2, 4 and 5
Flag_towersAboveThresholdTh2 = cms.Path(towersAboveThresholdTh2)
Flag_towersAboveThresholdTh4 = cms.Path(towersAboveThresholdTh4)
Flag_towersAboveThresholdTh5 = cms.Path(towersAboveThresholdTh5)
# select HF+ towers above threshold
Flag_hfPosTowers = cms.Path(hfPosTowers)
# select HF- towers above threshold
Flag_hfNegTowers = cms.Path(hfNegTowers)
# select HF+/HF- towers above threshold 2, 4 and 5
Flag_hfPosTowersTh2 = cms.Path(hfPosTowersTh2)
Flag_hfNegTowersTh2 = cms.Path(hfNegTowersTh2)
Flag_hfPosTowersTh4 = cms.Path(hfPosTowersTh4)
Flag_hfNegTowersTh4 = cms.Path(hfNegTowersTh4)
Flag_hfPosTowersTh5 = cms.Path(hfPosTowersTh5)
Flag_hfNegTowersTh5 = cms.Path(hfNegTowersTh5)
# require at least one HF+ tower above threshold
Flag_hfPosFilter = cms.Path(hfPosFilter)
Flag_hfNegFilter = cms.Path(hfNegFilter)
# require at least one HF+/HF- tower above threshold 2, 4and 5
Flag_hfPosFilterTh2 = cms.Path(hfPosFilterTh2)
Flag_hfNegFilterTh2 = cms.Path(hfNegFilterTh2)
Flag_hfPosFilterTh4 = cms.Path(hfPosFilterTh4)
Flag_hfNegFilterTh4 = cms.Path(hfNegFilterTh4)
Flag_hfPosFilterTh5 = cms.Path(hfPosFilterTh5)
Flag_hfNegFilterTh5 = cms.Path(hfNegFilterTh5)
# one HF tower above threshold on each side
Flag_hfCoincFilterTh2 = cms.Path(hfCoincFilterTh2)
Flag_hfCoincFilterTh3 = cms.Path(hfCoincFilterTh3)
Flag_hfCoincFilterTh4 = cms.Path(hfCoincFilterTh4)
Flag_hfCoincFilterTh5 = cms.Path(hfCoincFilterTh5)
# two HF towers above threshold on each side
Flag_hfPosFilter2 = cms.Path(hfPosFilter2)
Flag_hfNegFilter2 = cms.Path(hfNegFilter2)
Flag_hfPosFilter2Th2 = cms.Path(hfPosFilter2Th2)
Flag_hfNegFilter2Th2 = cms.Path(hfNegFilter2Th2)
Flag_hfPosFilter2Th4 = cms.Path(hfPosFilter2Th4)
Flag_hfNegFilter2Th4 = cms.Path(hfNegFilter2Th4)
Flag_hfPosFilter2Th5 = cms.Path(hfPosFilter2Th5)
Flag_hfNegFilter2Th5 = cms.Path(hfNegFilter2Th5)
Flag_hfCoincFilter2Th2 = cms.Path(hfCoincFilter2Th2)
Flag_hfCoincFilter2Th3 = cms.Path(hfCoincFilter2Th3)
Flag_hfCoincFilter2Th4 = cms.Path(hfCoincFilter2Th4)
Flag_hfCoincFilter2Th5 = cms.Path(hfCoincFilter2Th5)
#three HF towers above threshold on each side
Flag_hfPosFilter3 = cms.Path(hfPosFilter3)
Flag_hfNegFilter3 = cms.Path(hfNegFilter3)
Flag_hfPosFilter3Th2 = cms.Path(hfPosFilter3Th2)
Flag_hfNegFilter3Th2 = cms.Path(hfNegFilter3Th2)
Flag_hfPosFilter3Th4 = cms.Path(hfPosFilter3Th4)
Flag_hfNegFilter3Th4 = cms.Path(hfNegFilter3Th4)
Flag_hfPosFilter3Th5 = cms.Path(hfPosFilter3Th5)
Flag_hfNegFilter3Th5 = cms.Path(hfNegFilter3Th5)
Flag_hfCoincFilter3Th2 = cms.Path(hfCoincFilter3Th2)
Flag_hfCoincFilter3Th3 = cms.Path(hfCoincFilter3Th3)
Flag_hfCoincFilter3Th4 = cms.Path(hfCoincFilter3Th4)
Flag_hfCoincFilter3Th5 = cms.Path(hfCoincFilter3Th5)
#four HF towers above threshold on each side
Flag_hfPosFilter4 = cms.Path(hfPosFilter4)
Flag_hfNegFilter4 = cms.Path(hfNegFilter4)
Flag_hfPosFilter4Th2 = cms.Path(hfPosFilter4Th2)
Flag_hfNegFilter4Th2 = cms.Path(hfNegFilter4Th2)
Flag_hfPosFilter4Th4 = cms.Path(hfPosFilter4Th4)
Flag_hfNegFilter4Th4 = cms.Path(hfNegFilter4Th4)
Flag_hfPosFilter4Th5 = cms.Path(hfPosFilter4Th5)
Flag_hfNegFilter4Th5 = cms.Path(hfNegFilter4Th5)
Flag_hfCoincFilter4Th2 = cms.Path(hfCoincFilter4Th2)
Flag_hfCoincFilter4Th3 = cms.Path(hfCoincFilter4Th3)
Flag_hfCoincFilter4Th4 = cms.Path(hfCoincFilter4Th4)
Flag_hfCoincFilter4Th5 = cms.Path(hfCoincFilter4Th5)
#five hf towers above threshold on each side
Flag_hfPosFilter5 = cms.Path(hfPosFilter5)
Flag_hfNegFilter5 = cms.Path(hfNegFilter5)
Flag_hfPosFilter5Th2 = cms.Path(hfPosFilter5Th2)
Flag_hfNegFilter5Th2 = cms.Path(hfNegFilter5Th2)
Flag_hfPosFilter5Th4 = cms.Path(hfPosFilter5Th4)
Flag_hfNegFilter5Th4 = cms.Path(hfNegFilter5Th4)
Flag_hfPosFilter5Th5 = cms.Path(hfPosFilter5Th5)
Flag_hfNegFilter5Th5 = cms.Path(hfNegFilter5Th5)
Flag_hfCoincFilter5Th2 = cms.Path(hfCoincFilter5Th2)
Flag_hfCoincFilter5Th3 = cms.Path(hfCoincFilter5Th3)
Flag_hfCoincFilter5Th4 = cms.Path(hfCoincFilter5Th4)
Flag_hfCoincFilter5Th5 = cms.Path(hfCoincFilter5Th5)

# and the summary
Flag_HFFilters = cms.Path(hfFilters)

allhfFilterPaths=['towersAboveThreshold','towersAboveThresholdTh2','towersAboveThresholdTh4','towersAboveThresholdTh5','hfPosTowers','hfNegTowers','hfPosTowersTh2','hfNegTowersTh2','hfPosTowersTh4','hfNegTowersTh4','hfPosTowersTh5','hfNegTowersTh5','hfPosFilter','hfNegFilter','hfPosFilterTh2','hfNegFilterTh2','hfPosFilterTh4','hfNegFilterTh4','hfPosFilterTh5','hfNegFilterTh5','hfCoincFilterTh2','hfCoincFilterTh3','hfCoincFilterTh4','hfCoincFilterTh5','hfPosFilter2','hfNegFilter2','hfPosFilter2Th2','hfNegFilter2Th2','hfPosFilter2Th4','hfNegFilter2Th4','hfPosFilter2Th5','hfNegFilter2Th5','hfCoincFilter2Th2','hfCoincFilter2Th3','hfCoincFilter2Th4','hfCoincFilter2Th5','hfPosFilter3','hfNegFilter3','hfPosFilter3Th2','hfNegFilter3Th2','hfPosFilter3Th4','hfNegFilter3Th4','hfPosFilter3Th5','hfNegFilter3Th5','hfCoincFilter3Th2','hfCoincFilter3Th3','hfCoincFilter3Th4','hfCoincFilter3Th5','hfPosFilter4','hfNegFilter4','hfPosFilter4Th2','hfNegFilter4Th2','hfPosFilter4Th4','hfNegFilter4Th4','hfPosFilter4Th5','hfNegFilter4Th5','hfCoincFilter4Th2','hfCoincFilter4Th3','hfCoincFilter4Th4','hfCoincFilter4Th5','hfPosFilter5','hfNegFilter5','hfPosFilter5Th2','hfNegFilter5Th2','hfPosFilter5Th4','hfNegFilter5Th4','hfPosFilter5Th5','hfNegFilter5Th5','hfCoincFilter5Th2','hfCoincFilter5Th3','hfCoincFilter5Th4','hfCoincFilter5Th5','HFFilters']

#task does not accept sequence, that is why i remove hfCoincFilterXThY here
hfFilterPathsTask = cms.Task(
    towersAboveThreshold ,
    towersAboveThresholdTh2 ,
    towersAboveThresholdTh4 ,
    towersAboveThresholdTh5 ,
    hfPosTowers ,
    hfNegTowers ,
    hfPosTowersTh2 ,
    hfNegTowersTh2 ,
    hfPosTowersTh4 ,
    hfNegTowersTh4 ,
    hfPosTowersTh5 ,
    hfNegTowersTh5 ,
    hfPosFilter ,
    hfNegFilter ,
    hfPosFilterTh2 ,
    hfNegFilterTh2 ,
    hfPosFilterTh4 ,
    hfNegFilterTh4 ,
    hfPosFilterTh5 ,
    hfNegFilterTh5 ,
#    hfCoincFilterTh2 ,
#    hfCoincFilterTh3 ,
#    hfCoincFilterTh4 ,
#    hfCoincFilterTh5 ,
    hfPosFilter2 ,
    hfNegFilter2 ,
    hfPosFilter2Th2 ,
    hfNegFilter2Th2 ,
    hfPosFilter2Th4 ,
    hfNegFilter2Th4 ,
    hfPosFilter2Th5 ,
    hfNegFilter2Th5 ,
#    hfCoincFilter2Th2 ,
#    hfCoincFilter2Th3 ,
#    hfCoincFilter2Th4 ,
#    hfCoincFilter2Th5 ,
    hfPosFilter3 ,
    hfNegFilter3 ,
    hfPosFilter3Th2 ,
    hfNegFilter3Th2 ,
    hfPosFilter3Th4 ,
    hfNegFilter3Th4 ,
    hfPosFilter3Th5 ,
    hfNegFilter3Th5 ,
#    hfCoincFilter3Th2 ,
#    hfCoincFilter3Th3 ,
#    hfCoincFilter3Th4 ,
#    hfCoincFilter3Th5 ,
    hfPosFilter4 ,
    hfNegFilter4 ,
    hfPosFilter4Th2 ,
    hfNegFilter4Th2 ,
    hfPosFilter4Th4 ,
    hfNegFilter4Th4 ,
    hfPosFilter4Th5 ,
    hfNegFilter4Th5 ,
#    hfCoincFilter4Th2 ,
#   hfCoincFilter4Th3 ,
#    hfCoincFilter4Th4 ,
#    hfCoincFilter4Th5 ,
    hfPosFilter5 ,
    hfNegFilter5 ,
    hfPosFilter5Th2 ,
    hfNegFilter5Th2 ,
    hfPosFilter5Th4 ,
    hfNegFilter5Th4 ,
    hfPosFilter5Th5 ,
    hfNegFilter5Th5 
#    hfCoincFilter5Th2 ,
#    hfCoincFilter5Th3 ,
#    hfCoincFilter5Th4
#    hfCoincFilter5Th5
)

