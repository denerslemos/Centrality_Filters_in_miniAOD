// -*- C++ -*-
//
// Package:    Demo/DemoAnalyzer
// Class:      DemoAnalyzer
//
/**\class DemoAnalyzer DemoAnalyzer.cc Demo/DemoAnalyzer/plugins/DemoAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Dener De Souza Lemos
//         Created:  Sat, 09 May 2020 14:47:10 GMT
//
//


// system include files

#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include <memory>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/V0Candidate/interface/V0Candidate.h"
#include "DataFormats/Candidate/interface/VertexCompositeCandidate.h"
#include "DataFormats/Candidate/interface/VertexCompositeCandidateFwd.h"

#include "DataFormats/TrackReco/interface/DeDxData.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/RecoCandidate/interface/TrackAssociation.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"
#include "TrackingTools/PatternTools/interface/TSCBLBuilderNoMaterial.h"

#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"

#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"

#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include <Math/Functions.h>
#include <Math/SVector.h>
#include <Math/SMatrix.h>

#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include "TVector3.h"
#include <vector>
#include <map>


using namespace std;
using namespace edm;
using namespace reco;
using namespace pat;

//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.



class DemoAnalyzer : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit DemoAnalyzer(const edm::ParameterSet&);
      ~DemoAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
        edm::EDGetTokenT<pat::PackedCandidateCollection> srcPFcand_;
        edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
	int ev=0;
	int evpass=0,evfail=0;
	void initHistos(const edm::Service<TFileService> & fs);

	TH1F *towersAboveThreshold;
	TH1F *towersAboveThresholdTh2;
	TH1F *towersAboveThresholdTh4;
	TH1F *towersAboveThresholdTh5;
	TH1F *hfPosTowers;
	TH1F *hfNegTowers;
	TH1F *hfPosTowersTh2;
	TH1F *hfNegTowersTh2;
	TH1F *hfPosTowersTh4;
	TH1F *hfNegTowersTh4;
	TH1F *hfPosTowersTh5;
	TH1F *hfNegTowersTh5;
	TH1F *hfPosFilter;
	TH1F *hfNegFilter;
	TH1F *hfPosFilterTh2;
	TH1F *hfNegFilterTh2;
	TH1F *hfPosFilterTh4;
	TH1F *hfNegFilterTh4;
	TH1F *hfPosFilterTh5;
	TH1F *hfNegFilterTh5;
	TH1F *hfCoincFilterTh2;
	TH1F *hfCoincFilterTh3;
	TH1F *hfCoincFilterTh4;
	TH1F *hfCoincFilterTh5;
	TH1F *hfPosFilter2;
	TH1F *hfNegFilter2;
	TH1F *hfPosFilter2Th2;
	TH1F *hfNegFilter2Th2;
	TH1F *hfPosFilter2Th4;
	TH1F *hfNegFilter2Th4;
	TH1F *hfPosFilter2Th5;
	TH1F *hfNegFilter2Th5;
	TH1F *hfCoincFilter2Th2;
	TH1F *hfCoincFilter2Th3;
	TH1F *hfCoincFilter2Th4;
	TH1F *hfCoincFilter2Th5;
	TH1F *hfPosFilter3;
	TH1F *hfNegFilter3;
	TH1F *hfPosFilter3Th2;
	TH1F *hfNegFilter3Th2;
	TH1F *hfPosFilter3Th4;
	TH1F *hfNegFilter3Th4;
	TH1F *hfPosFilter3Th5;
	TH1F *hfNegFilter3Th5;
	TH1F *hfCoincFilter3Th2;
	TH1F *hfCoincFilter3Th3;
	TH1F *hfCoincFilter3Th4;
	TH1F *hfCoincFilter3Th5;
	TH1F *hfPosFilter4;
	TH1F *hfNegFilter4;
	TH1F *hfPosFilter4Th2;
	TH1F *hfNegFilter4Th2;
	TH1F *hfPosFilter4Th4;
	TH1F *hfNegFilter4Th4;
	TH1F *hfPosFilter4Th5;
	TH1F *hfNegFilter4Th5;
	TH1F *hfCoincFilter4Th2;
	TH1F *hfCoincFilter4Th3;
	TH1F *hfCoincFilter4Th4;
	TH1F *hfCoincFilter4Th5;
	TH1F *hfPosFilter5;
	TH1F *hfNegFilter5;
	TH1F *hfPosFilter5Th2;
	TH1F *hfNegFilter5Th2;
	TH1F *hfPosFilter5Th4;
	TH1F *hfNegFilter5Th4;
	TH1F *hfPosFilter5Th5;
	TH1F *hfNegFilter5Th5;
	TH1F *hfCoincFilter5Th2;
	TH1F *hfCoincFilter5Th3;
	TH1F *hfCoincFilter5Th4;
	TH1F *hfCoincFilter5Th5;
 
        TH1F *tk_Pt_;
        TH1F *tk_Eta_;
        TH1F *tk_Phi_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)
 :
//  tracksToken_(consumes<TrackCollection>(iConfig.getUntrackedParameter<edm::InputTag>("tracks")))
srcPFcand_(consumes<pat::PackedCandidateCollection>(iConfig.getParameter<edm::InputTag>("srcPFcand"))),
triggerBits_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("trigger")))
{
  edm::Service<TFileService> fs;
  initHistos(fs);
   //now do what ever initialization is needed
}


DemoAnalyzer::~DemoAnalyzer()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
 
    edm::Handle<pat::PackedCandidateCollection> pfCandidates;
    iEvent.getByToken(srcPFcand_,pfCandidates);

    edm::Handle<edm::TriggerResults> triggerBits;
    iEvent.getByToken(triggerBits_, triggerBits);
    const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);

    bool phfCoincFilter2Th4=false;

    if(ev==0){std::cout << "\n === TRIGGER PATHS === " << std::endl;}

    for (unsigned int i = 0, n = triggerBits->size(); i < n; ++i) {

    if(ev==0){std::cout << "Trigger " << i << " : " << names.triggerName(i) << endl;}//(triggerBits->accept(i) ? "PASS" : "FAIL")  << std::endl;}

    if(names.triggerName(i)=="Flag_towersAboveThreshold"){towersAboveThreshold->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_towersAboveThresholdTh2"){towersAboveThresholdTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_towersAboveThresholdTh4"){towersAboveThresholdTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_towersAboveThresholdTh5"){towersAboveThresholdTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosTowers"){hfPosTowers->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegTowers"){hfNegTowers->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosTowersTh2"){hfPosTowersTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegTowersTh2"){hfNegTowersTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosTowersTh4"){hfPosTowersTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegTowersTh4"){hfNegTowersTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosTowersTh5"){hfPosTowersTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegTowersTh5"){hfNegTowersTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter"){hfPosFilter->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter"){hfNegFilter->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilterTh2"){hfPosFilterTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilterTh2"){hfNegFilterTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilterTh4"){hfPosFilterTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilterTh4"){hfNegFilterTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilterTh5"){hfPosFilterTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilterTh5"){hfNegFilterTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilterTh2"){hfCoincFilterTh2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilterTh3"){hfCoincFilterTh3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilterTh4"){hfCoincFilterTh4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilterTh5"){hfCoincFilterTh5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter2"){hfPosFilter2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter2"){hfNegFilter2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter2Th2"){hfPosFilter2Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter2Th2"){hfNegFilter2Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter2Th4"){hfPosFilter2Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter2Th4"){hfNegFilter2Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter2Th5"){hfPosFilter2Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter2Th5"){hfNegFilter2Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter2Th2"){hfCoincFilter2Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter2Th3"){hfCoincFilter2Th3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter2Th4"){hfCoincFilter2Th4->Fill(triggerBits->accept(i)); phfCoincFilter2Th4=triggerBits->accept(i);}
    if(names.triggerName(i)=="Flag_hfCoincFilter2Th5"){hfCoincFilter2Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter3"){hfPosFilter3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter3"){hfNegFilter3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter3Th2"){hfPosFilter3Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter3Th2"){hfNegFilter3Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter3Th4"){hfPosFilter3Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter3Th4"){hfNegFilter3Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter3Th5"){hfPosFilter3Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter3Th5"){hfNegFilter3Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter3Th2"){hfCoincFilter3Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter3Th3"){hfCoincFilter3Th3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter3Th4"){hfCoincFilter3Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter3Th5"){hfCoincFilter3Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter4"){hfPosFilter4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter4"){hfNegFilter4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter4Th2"){hfPosFilter4Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter4Th2"){hfNegFilter4Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter4Th4"){hfPosFilter4Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter4Th4"){hfNegFilter4Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter4Th5"){hfPosFilter4Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter4Th5"){hfNegFilter4Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter4Th2"){hfCoincFilter4Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter4Th3"){hfCoincFilter4Th3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter4Th4"){hfCoincFilter4Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter4Th5"){hfCoincFilter4Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter5"){hfPosFilter5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter5"){hfNegFilter5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter5Th2"){hfPosFilter5Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter5Th2"){hfNegFilter5Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter5Th4"){hfPosFilter5Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter5Th4"){hfNegFilter5Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfPosFilter5Th5"){hfPosFilter5Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfNegFilter5Th5"){hfNegFilter5Th5->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter5Th2"){hfCoincFilter5Th2->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter5Th3"){hfCoincFilter5Th3->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter5Th4"){hfCoincFilter5Th4->Fill(triggerBits->accept(i));}
    if(names.triggerName(i)=="Flag_hfCoincFilter5Th5"){hfCoincFilter5Th5->Fill(triggerBits->accept(i));}

    }


    ev=ev+1;
    if(phfCoincFilter2Th4==false){evfail=evfail+1;}else{evpass=evpass+1;}

    if(phfCoincFilter2Th4==false)return;
//loop over tracks
   for(unsigned int i = 0, n = pfCandidates->size(); i < n; ++i){
       const pat::PackedCandidate &pf = (*pfCandidates)[i];
       if(!(pf.hasTrackDetails()))continue;
       const reco::Track &trk = pf.pseudoTrack();
       tk_Pt_->Fill(trk.pt());    
       tk_Eta_->Fill(trk.eta()); 
       tk_Phi_->Fill(trk.phi());
   }
}


// ------------ method called once each job just before starting event loop  ------------
void
DemoAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
DemoAnalyzer::endJob()
{
cout << "Total of events: " << ev << endl;
cout << "Pass: " << evpass << endl;
cout << "Fail: " << evfail << endl;

}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}


void DemoAnalyzer::initHistos(const edm::Service<TFileService> & fs){

 TFileDirectory filt = fs->mkdir( "Event_Filters" );

towersAboveThreshold = filt.make<TH1F>("towersAboveThreshold","towersAboveThreshold",3,0,3);
towersAboveThresholdTh2 = filt.make<TH1F>("towersAboveThresholdTh2","towersAboveThresholdTh2",3,0,3);
towersAboveThresholdTh4 = filt.make<TH1F>("towersAboveThresholdTh4","towersAboveThresholdTh4",3,0,3);
towersAboveThresholdTh5 = filt.make<TH1F>("towersAboveThresholdTh5","towersAboveThresholdTh5",3,0,3);
hfPosTowers = filt.make<TH1F>("hfPosTowers","hfPosTowers",3,0,3);
hfNegTowers = filt.make<TH1F>("hfNegTowers","hfNegTowers",3,0,3);
hfPosTowersTh2 = filt.make<TH1F>("hfPosTowersTh2","hfPosTowersTh2",3,0,3);
hfNegTowersTh2 = filt.make<TH1F>("hfNegTowersTh2","hfNegTowersTh2",3,0,3);
hfPosTowersTh4 = filt.make<TH1F>("hfPosTowersTh4","hfPosTowersTh4",3,0,3);
hfNegTowersTh4 = filt.make<TH1F>("hfNegTowersTh4","hfNegTowersTh4",3,0,3);
hfPosTowersTh5 = filt.make<TH1F>("hfPosTowersTh5","hfPosTowersTh5",3,0,3);
hfNegTowersTh5 = filt.make<TH1F>("hfNegTowersTh5","hfNegTowersTh5",3,0,3);
hfPosFilter = filt.make<TH1F>("hfPosFilter","hfPosFilter",3,0,3);
hfNegFilter = filt.make<TH1F>("hfNegFilter","hfNegFilter",3,0,3);
hfPosFilterTh2 = filt.make<TH1F>("hfPosFilterTh2","hfPosFilterTh2",3,0,3);
hfNegFilterTh2 = filt.make<TH1F>("hfNegFilterTh2","hfNegFilterTh2",3,0,3);
hfPosFilterTh4 = filt.make<TH1F>("hfPosFilterTh4","hfPosFilterTh4",3,0,3);
hfNegFilterTh4 = filt.make<TH1F>("hfNegFilterTh4","hfNegFilterTh4",3,0,3);
hfPosFilterTh5 = filt.make<TH1F>("hfPosFilterTh5","hfPosFilterTh5",3,0,3);
hfNegFilterTh5 = filt.make<TH1F>("hfNegFilterTh5","hfNegFilterTh5",3,0,3);
hfCoincFilterTh2 = filt.make<TH1F>("hfCoincFilterTh2","hfCoincFilterTh2",3,0,3);
hfCoincFilterTh3 = filt.make<TH1F>("hfCoincFilterTh3","hfCoincFilterTh3",3,0,3);
hfCoincFilterTh4 = filt.make<TH1F>("hfCoincFilterTh4","hfCoincFilterTh4",3,0,3);
hfCoincFilterTh5 = filt.make<TH1F>("hfCoincFilterTh5","hfCoincFilterTh5",3,0,3);
hfPosFilter2 = filt.make<TH1F>("hfPosFilter2","hfPosFilter2",3,0,3);
hfNegFilter2 = filt.make<TH1F>("hfNegFilter2","hfNegFilter2",3,0,3);
hfPosFilter2Th2 = filt.make<TH1F>("hfPosFilter2Th2","hfPosFilter2Th2",3,0,3);
hfNegFilter2Th2 = filt.make<TH1F>("hfNegFilter2Th2","hfNegFilter2Th2",3,0,3);
hfPosFilter2Th4 = filt.make<TH1F>("hfPosFilter2Th4","hfPosFilter2Th4",3,0,3);
hfNegFilter2Th4 = filt.make<TH1F>("hfNegFilter2Th4","hfNegFilter2Th4",3,0,3);
hfPosFilter2Th5 = filt.make<TH1F>("hfPosFilter2Th5","hfPosFilter2Th5",3,0,3);
hfNegFilter2Th5 = filt.make<TH1F>("hfNegFilter2Th5","hfNegFilter2Th5",3,0,3);
hfCoincFilter2Th2 = filt.make<TH1F>("hfCoincFilter2Th2","hfCoincFilter2Th2",3,0,3);
hfCoincFilter2Th3 = filt.make<TH1F>("hfCoincFilter2Th3","hfCoincFilter2Th3",3,0,3);
hfCoincFilter2Th4 = filt.make<TH1F>("hfCoincFilter2Th4","hfCoincFilter2Th4",3,0,3);
hfCoincFilter2Th5 = filt.make<TH1F>("hfCoincFilter2Th5","hfCoincFilter2Th5",3,0,3);
hfPosFilter3 = filt.make<TH1F>("hfPosFilter3","hfPosFilter3",3,0,3);
hfNegFilter3 = filt.make<TH1F>("hfNegFilter3","hfNegFilter3",3,0,3);
hfPosFilter3Th2 = filt.make<TH1F>("hfPosFilter3Th2","hfPosFilter3Th2",3,0,3);
hfNegFilter3Th2 = filt.make<TH1F>("hfNegFilter3Th2","hfNegFilter3Th2",3,0,3);
hfPosFilter3Th4 = filt.make<TH1F>("hfPosFilter3Th4","hfPosFilter3Th4",3,0,3);
hfNegFilter3Th4 = filt.make<TH1F>("hfNegFilter3Th4","hfNegFilter3Th4",3,0,3);
hfPosFilter3Th5 = filt.make<TH1F>("hfPosFilter3Th5","hfPosFilter3Th5",3,0,3);
hfNegFilter3Th5 = filt.make<TH1F>("hfNegFilter3Th5","hfNegFilter3Th5",3,0,3);
hfCoincFilter3Th2 = filt.make<TH1F>("hfCoincFilter3Th2","hfCoincFilter3Th2",3,0,3);
hfCoincFilter3Th3 = filt.make<TH1F>("hfCoincFilter3Th3","hfCoincFilter3Th3",3,0,3);
hfCoincFilter3Th4 = filt.make<TH1F>("hfCoincFilter3Th4","hfCoincFilter3Th4",3,0,3);
hfCoincFilter3Th5 = filt.make<TH1F>("hfCoincFilter3Th5","hfCoincFilter3Th5",3,0,3);
hfPosFilter4 = filt.make<TH1F>("hfPosFilter4","hfPosFilter4",3,0,3);
hfNegFilter4 = filt.make<TH1F>("hfNegFilter4","hfNegFilter4",3,0,3);
hfPosFilter4Th2 = filt.make<TH1F>("hfPosFilter4Th2","hfPosFilter4Th2",3,0,3);
hfNegFilter4Th2 = filt.make<TH1F>("hfNegFilter4Th2","hfNegFilter4Th2",3,0,3);
hfPosFilter4Th4 = filt.make<TH1F>("hfPosFilter4Th4","hfPosFilter4Th4",3,0,3);
hfNegFilter4Th4 = filt.make<TH1F>("hfNegFilter4Th4","hfNegFilter4Th4",3,0,3);
hfPosFilter4Th5 = filt.make<TH1F>("hfPosFilter4Th5","hfPosFilter4Th5",3,0,3);
hfNegFilter4Th5 = filt.make<TH1F>("hfNegFilter4Th5","hfNegFilter4Th5",3,0,3);
hfCoincFilter4Th2 = filt.make<TH1F>("hfCoincFilter4Th2","hfCoincFilter4Th2",3,0,3);
hfCoincFilter4Th3 = filt.make<TH1F>("hfCoincFilter4Th3","hfCoincFilter4Th3",3,0,3);
hfCoincFilter4Th4 = filt.make<TH1F>("hfCoincFilter4Th4","hfCoincFilter4Th4",3,0,3);
hfCoincFilter4Th5 = filt.make<TH1F>("hfCoincFilter4Th5","hfCoincFilter4Th5",3,0,3);
hfPosFilter5 = filt.make<TH1F>("hfPosFilter5","hfPosFilter5",3,0,3);
hfNegFilter5 = filt.make<TH1F>("hfNegFilter5","hfNegFilter5",3,0,3);
hfPosFilter5Th2 = filt.make<TH1F>("hfPosFilter5Th2","hfPosFilter5Th2",3,0,3);
hfNegFilter5Th2 = filt.make<TH1F>("hfNegFilter5Th2","hfNegFilter5Th2",3,0,3);
hfPosFilter5Th4 = filt.make<TH1F>("hfPosFilter5Th4","hfPosFilter5Th4",3,0,3);
hfNegFilter5Th4 = filt.make<TH1F>("hfNegFilter5Th4","hfNegFilter5Th4",3,0,3);
hfPosFilter5Th5 = filt.make<TH1F>("hfPosFilter5Th5","hfPosFilter5Th5",3,0,3);
hfNegFilter5Th5 = filt.make<TH1F>("hfNegFilter5Th5","hfNegFilter5Th5",3,0,3);
hfCoincFilter5Th2 = filt.make<TH1F>("hfCoincFilter5Th2","hfCoincFilter5Th2",3,0,3);
hfCoincFilter5Th3 = filt.make<TH1F>("hfCoincFilter5Th3","hfCoincFilter5Th3",3,0,3);
hfCoincFilter5Th4 = filt.make<TH1F>("hfCoincFilter5Th4","hfCoincFilter5Th4",3,0,3);
hfCoincFilter5Th5 = filt.make<TH1F>("hfCoincFilter5Th5","hfCoincFilter5Th5",3,0,3);

 TFileDirectory trk = fs->mkdir( "Trk_info" );

tk_Pt_=  trk.make<TH1F>("tk_pt","tk_pt",200,0,10.);
tk_Eta_= trk.make<TH1F>("tk_eta","tk_eta",100,-2.5,2.5);
tk_Phi_= trk.make<TH1F>("tk_phi","tk_phi",100,-3.2,3.2);

}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
