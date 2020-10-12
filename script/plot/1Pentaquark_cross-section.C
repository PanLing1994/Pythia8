/// \file
/// \ingroup tutorial_graphs
/// \notebook
/// Create and Draw a TMultiGraph.
///
/// \macro_image
/// \macro_code
///
/// \author Rene Brun


#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void multigraph()
{
   gStyle->SetOptFit();
   auto c1 = new TCanvas("c1","multigraph");
   c1->SetLogy();

   auto mg = new TMultiGraph();

  const Int_t n1 = 10;
   Double_t px1[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,12};
   Double_t py1[] = {0.45,0.94,0.77,0.47,0.28,0.15,0.074,0.027,0.0068,0.003};
   Double_t ex1[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 10;
   Double_t px2[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,12};
   Double_t py2[] = {3.0,6.3,5.2,3.2,1.9,0.98,0.49,0.18,0.045,0.02};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

auto leg = new TLegend(.1,.7,.3,.9,"molecule structure #Sigma_{c}#bar{D}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"momentum scale 0.5GeV");
leg->AddEntry(gr2,"momentum scale 1GeV");

mg->Draw("ap");
mg->GetXaxis()->SetTitle("pT [GeV]");
mg->GetYaxis()->SetTitle("d#sigma/dpT [nb/GeV]");

leg->Draw();
//gPad->Update();
//gPad->Modified();

//c1->Modified();

   //force drawing of canvas to generate the fit TPaveStats
  // c1->Update();
//   auto stats1 = (TPaveStats*)gr1->GetListOfFunctions()->FindObject("stats");
 //  auto stats2 = (TPaveStats*)gr2->GetListOfFunctions()->FindObject("stats");
 //  auto stats3 = (TPaveStats*)gr3->GetListOfFunctions()->FindObject("stats");
 //  auto stats4 = (TPaveStats*)gr4->GetListOfFunctions()->FindObject("stats");
 //  stats1->SetTextColor(kBlue);
 //  stats2->SetTextColor(kGreen);
 //  stats3->SetTextColor(kYellow);
 //  stats4->SetTextColor(kRed);
   //stats1->SetX1NDC(0.12); stats1->SetX2NDC(0.32); stats1->SetY1NDC(0.75);
   //stats2->SetX1NDC(0.72); stats2->SetX2NDC(0.92); stats2->SetY1NDC(0.78);
}
