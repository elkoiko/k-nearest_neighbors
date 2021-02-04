#include "Data.hpp"
using namespace std;

    Data::Data() : _nbFeatures(0), _nbSamples(0)
    {
    }

    Data::Data(string strFilePath)
    {
        // TODO: Implement exceptions
        
        // Open strFilePath to get a stream
        string line;
        ifstream dataSource;

        dataSource.open(strFilePath);
        if (dataSource.is_open())
        {
            _samples.clear();
            // Read First line = nbSamples
            dataSource >> _nbSamples;
            // Read second line = nbFeatures per sample
            dataSource >> _nbFeatures >> line; // Getting _nbFeatures and going to the 3rd line
            // Loading all samples
            while (getline(dataSource, line))
            {
                Sample sample(line);
                add(sample);
            }

            // Finally we check if enough lines were read
            if (_samples.size() < _nbSamples)
            {
                cerr << "Warning, expecting " << _nbSamples << " samples but retrieved only " << _samples.size() << endl;
            }
            dataSource.close();
        }
        else
        {
            cerr << "data file doesn't exist";
        }
    }

    void Data::add(Sample& sample)
    {
        _samples.push_back(sample);
    }

    // Operators
    double Data::operator[](int index) const
    {
        // TODO: Getter to samples vector
        return 0.0;
    }

    string Data::toString() const
    {
        return "size=" + to_string(_samples.size());
    }
