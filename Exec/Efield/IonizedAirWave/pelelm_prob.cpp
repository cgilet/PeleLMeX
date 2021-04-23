#include <PeleLM.H>
#include <AMReX_ParmParse.H>
#include <pmf.H>

void PeleLM::readProbParm()
{
   amrex::ParmParse pp("prob");
   
   std::string type;
   pp.query("P_mean", prob_parm->P_mean);
   pp.query("standoff", PeleLM::prob_parm->standoff);
   pp.query("pertmag",  PeleLM::prob_parm->pertmag);

   pp.query("PhiV_y_hi", PeleLM::prob_parm->phiV_hiy);
   pp.query("PhiV_y_lo", PeleLM::prob_parm->phiV_loy);

   std::string pmf_datafile;
   pp.query("pmf_datafile", pmf_datafile);
   int pmf_do_average = 1;
   PMF::read_pmf(pmf_datafile, pmf_do_average);
}
