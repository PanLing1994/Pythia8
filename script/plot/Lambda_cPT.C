   gStyle->SetOptFit();
   auto c1 = new TCanvas("c1","multigraph");
   c1->SetLogy();

const Int_t n2 = 5;
   Double_t px2[] = {1.5,2.5,3.5,5,7};
   Double_t py2[] = {9,6.2,3.4,1.35,0.31};
   Double_t ex2[] = {0.5,0.5,0.5,1,1};
   Double_t ey2[] = {0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kBlue);
   gr2->SetMarkerStyle(22);

   double ax[] = {1.5, 2.5, 3.5, 5, 7};
   double ay[] = {110, 60, 27, 8.8,2};
   double aexl[] = {0.5, 0.5, 0.5, 1,1};
   double aexh[] = {0.5, 0.5, 0.5, 1,1};
   double aeyl[] = {30, 10, 3,0.8, 0.4};
   double aeyh[] = {34, 10, 4, 1.2, 0.2};
   auto gae = new TGraphAsymmErrors(5, ax, ay, aexl, aexh, aeyl, aeyh);
   gae->SetFillColor(2);
   gae->SetFillStyle(3001);
   gae->SetMinimum(0);
 
auto leg = new TLegend(.1,.7,.3,.9,"");
leg->SetFillColor(0);
leg->AddEntry(gr2,"Madgraph5+Pythia8");
leg->AddEntry(gae,"LHC");

auto leg1 = new TLegend(.1,.7,.2,.5,"");
leg1->SetFillColor(0);
leg1->AddEntry(gr2,"c_{(P_{T})}>2GeV, c_{(|#eta|)}<0.5");
leg1->AddEntry(gae,"|#eta|<0.5");
  gae->Draw("a2");
   gae->Draw("p");
   gr2->Draw("Psame")
   gae->SetTitle("#Lambda_{c}^{+} in pp at 7TeV;P_{T} [GeV/c];d#sigma/dP_{T} [#mub/GeV^{-1}c]");


leg->Draw();
leg1->Draw();






















