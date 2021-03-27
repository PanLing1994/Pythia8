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
   Double_t px1[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py1[] = {0.0076,0.0081,0.0022,0.00094,0.00048,0.00022,0.00014,0.00009,0.00003,0.0000024};
   Double_t ex1[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey1[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr1 = new TGraphErrors(n1,px1,py1,ex1,ey1);
  // gr1->SetLineColor(kBlue);
   gr1->SetMarkerColor(kBlue);
   gr1->SetMarkerStyle(50);
   mg->Add(gr1);

const Int_t n2 = 10;
   Double_t px2[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py2[] = {0.038,0.04,0.011,0.0047,0.0024,0.0011,0.0007,0.00045,0.00014,0.000012};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey2[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kGreen);
   gr2->SetMarkerStyle(20);
   mg->Add(gr2);

const Int_t n3 = 10;
   Double_t px3[] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,10,14};
   Double_t py3[] = {0.577,0.61,0.167,0.071,0.036,0.0167,0.011,0.0068,0.002,0.00018};
   Double_t ex3[] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,2,2};
   Double_t ey3[] = {0,0,0,0,0,0,0,0,0,0};
   auto gr3 = new TGraphErrors(n3,px3,py3,ex3,ey3);
   gr3->SetMarkerColor(kRed);
   gr3->SetMarkerStyle(80);
   mg->Add(gr3);


auto leg = new TLegend(.1,.7,.3,.9,"molecule structure #Sigma_{c}^{++}D^{-}");
leg->SetFillColor(0);
leg->AddEntry(gr1,"0.5m_{#pi}");
leg->AddEntry(gr2,"m_{#pi}");
leg->AddEntry(gr3,"2m_{#pi}");

mg->Draw("ap");
mg->GetXaxis()->SetTitle("pT [GeV]");
mg->GetYaxis()->SetTitle("#sigma [nb]");

leg->Draw();
}
