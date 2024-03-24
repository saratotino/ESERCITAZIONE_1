#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <fstream>

double mappa(double value)
{
    double a1 = 1;
    double b1 = 5;
    double a2 = -1;
    double b2 = 2;
    double m = (b2 - a2)/(b1 - a1);
    double q = a2 - m * a1;
    double mapvalue = m * value + q;

    return mapvalue;

}

int main()
{

    std::string nameFile = "data.csv";
    std::ifstream fstr(nameFile);

    std::string outputFile = "results.csv";
    std::ofstream file(outputFile);



    if(file.fail())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    file << std::scientific;
    file << std::setprecision(16);

    double val;
    double val_mappato = 0;
    double sum = 0;
    double mean = 0;
    unsigned int N = 1;


    file << "# N  ; Mean" << std::endl; //io come separatore tra colonne su Excel ho ";" se la formattazione è sbagliata cambiare con il valore richiesto

    while (fstr >> val)
    {
        val_mappato = mappa(val);
        sum += val_mappato;
        mean = sum / N;
        //Il results.csv avrà i valori superiori a 1 sbagliati perchè sulla versione italiana i delimitatori di decimali(.) e miagliaia(,) sono invertiti rispetto alla versione americana.
        //Per la corretta visualizzazione bisogna cambiare le impostazioni di Excel.


        file << N << ";" << std::scientific << std::setprecision(16) << mean << std::endl;
        //io come separatore tra colonne su Excel ho ";" se la formattazione è sbagliata cambiare con il valore richiesto

        N++;
    }
    fstr.close();
    file.close();



    return 0;
}
