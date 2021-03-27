   gStyle->SetOptFit();
   auto c1 = new TCanvas("c1","multigraph");
   c1->SetLogy();

const Int_t n2 = 6;
   Double_t px2[] = {2.5,3.5,4.5,5.5,7,10};
   Double_t py2[] = {18,9,4.5,2,1.1,0.46};
   Double_t ex2[] = {0.5,0.5,0.5,0.5,1,2};
   Double_t ey2[] = {0,0,0,0,0,0};
   auto gr2 = new TGraphErrors(n2,px2,py2,ex2,ey2);
   gr2->SetMarkerColor(kBlue);
   gr2->SetMarkerStyle(22);

   double ax[] = {2.5, 3.5, 4.5, 5.5, 7,10};
   double ay[] = {110, 68, 22.5, 13, 6,2};
   double aexl[] = {0.5, 0.5, 0.5, 0.5, 1,2};
   double aexh[] = {0.5, 0.5, 0.5, 0.5, 1,2};
   double aeyl[] = {30, 18, 4.5,2, 1.3, 0.7};
   double aeyh[] = {30, 20, 5, 2,1.2, 0.7};
   auto gae = new TGraphAsymmErrors(6, ax, ay, aexl, aexh, aeyl, aeyh);
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
   gae->SetTitle("D^{0} in pp at 7TeV;P_{T} [GeV/c];d#sigma/dP_{T} [#mub/GeV^{-1}c]");


leg->Draw();
leg1->Draw();






















