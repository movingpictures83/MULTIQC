#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MULTIQCPlugin.h"

void MULTIQCPlugin::input(std::string file) {
 inputfile = file;
}

void MULTIQCPlugin::run() {
   
}

void MULTIQCPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   std::string command = "multiqc "+inputfile+" -o "+file;
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<MULTIQCPlugin> MULTIQCPluginProxy = PluginProxy<MULTIQCPlugin>("MULTIQC", PluginManager::getInstance());
