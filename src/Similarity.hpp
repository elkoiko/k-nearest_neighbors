#ifndef SIMILARITY_H
# define SIMILARITY_H

typedef struct Similarity {
    int predictedTag = -1;
    int tag = -1;
    double value = 0.0; // The greater the better
} Similarity;

#endif