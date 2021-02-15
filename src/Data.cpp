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
        int nbExpectedSamples = 0;
        ifstream dataSource;

        dataSource.open(strFilePath);
        if (dataSource.is_open())
        {
            _samples.clear();
            // Read First line = nbSamples
            dataSource >> nbExpectedSamples;
            // Read second line = nbFeatures per sample
            dataSource >> _nbFeatures; // Getting _nbFeatures
            // Just going to the 3rd line
            getline(dataSource, line);
            // Loading all samples
            while (getline(dataSource, line))
            {
                Sample sample(line);
                add(sample);
            }

            // Finally we check if enough lines were read
            if (_samples.size() < nbExpectedSamples)
            {
                cerr << "Warning, expecting " << nbExpectedSamples << " samples but retrieved only " << _samples.size() << endl;
            }
            dataSource.close();
        }
        else
        {
            cerr << "Data file " << strFilePath << " does not exist." << endl;
        }
    }

    void Data::add(Sample& sample)
    {
        _samples.push_back(sample);
        _nbSamples = _samples.size();
    }

    // Operators
    const Sample& Data::operator[](int index) const
    {
        return _samples[index];
    }

    // Returns a string containing all the tags for each sample contained in data
    string Data::toString() const
    {
        string outPut = "size=" + to_string(_samples.size()) + " tags=[ ";

        for (const Sample& sample: _samples)
        {
            outPut += sample.toString() + " ";
        }
        return outPut + "]";
    }

    std::vector<Sample>::const_iterator Data::begin() const
    {
        return _samples.begin();
    }

    std::vector<Sample>::const_iterator Data::end() const
    {
        return _samples.end();
    }
