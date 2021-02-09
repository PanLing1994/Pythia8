/// \file
/// \ingroup tutorial_tree
/// \notebook -nodraw
///  Read data from an ascii file and create a root file with an histogram and an ntuple.
///  See a variant of this macro in basic2.C.
///
/// \macro_code
///
/// \author Rene Brun

#include "Riostream.h"
void basic() {
// read file $ROOTSYS/tutorials/tree/basic.dat
// this file has 3 columns of float data
   TString dir = gROOT->GetTutorialDir();
   dir.Append("/tree/");
   dir.ReplaceAll("/./","/");
   ifstream in;
   in.open(Form("%s4P_pT.txt",dir.Data()));

   Float_t x;
   Int_t nlines = 0;
   auto f = TFile::Open("basic.root","RECREATE");
   TH1F h1("h1","pT distribution",300,0,30);
   TNtuple ntuple("ntuple","data from ascii file","x");

   while (1) {
      in >> x ;
      if (!in.good()) break;
      if (nlines < 5) printf("x=%8f\n",x);
      h1.Fill(x);
      ntuple.Fill(x);
      nlines++;
   }
   printf(" found %d points\n",nlines);

   in.close();

   f->Write();
}
