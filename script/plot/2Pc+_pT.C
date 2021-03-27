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

  const Int_t n1 = 7;
   Double_t px1[] = {0.5,1.5,2.5,3.5,4.5,5.5,7};
   Double_t py1[] = {39,14.1,3.16,1.57,0.71,0.35,0.18};
   Double_t ex1[] = {0.5,0.5,0.5,0.5,0.5,0.5,1};
   Double_t ey1[] = {0,0,0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

   const Int_t n2 = 7;
   Double_t px2[] = {0.5,1.5,2.5,3.5,4.5,5.5,7};
   Double_t py2[] = {10,4.17,1.43,0.53,0.33,0.16,0.08};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,0.5,0.5,1};
   Double_t ey2[] = {0,0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(50);
   mg->Add(gr2);

const Int_t n3 = 7;
   Double_t px3[] = {0.5,1.5,2.5,3.5,4.5,5.5,7};
   Double_t py3[] = {13.9,5.8,2,0.74,0.46,0.14,0.07};
   Double_t ex3[] = {0.5,0.5,0.5,0.5,0.5,0.5,1};
   Double_t ey3[] = {0,0,0,0,0,0,0};
   auto gr3 = new TGraphErrors(n3,px3,py3,ex3,ey3);
   gr3->SetMarkerColor(kRed);
   gr3->SetMarkerStyle(50);
   mg->Add(gr3);


auto leg = new TLegend(.1,.7,.3,.9,"P_{c}^{+}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"P_{c}(4380)^{+}");
leg->AddEntry(gr2,"P_{c}(4457)^{+}");
leg->AddEntry(gr3,"P_{c}(3/2^{-})");

mg->Draw("ap");
mg->GetXaxis()->SetTitle("P_{T} [GeV/c]");
mg->GetYaxis()->SetTitle("d#sigma/dP_{T} [nbGeV^{-1}c]");

leg->Draw();
}
