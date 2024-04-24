#include <stdlib.h>
#include "lib/nn.h"


int main() {
    int num_layers = 3;
    int num_neurons_per_layer[] = {5, 3, 2};
    
    network* net = create_network(num_layers, num_neurons_per_layer);
    link_layers(net);
    
    // Now net contains the initialized network with the respective number of layers and neurons,
    // and the layers are linked according to your connectivity rules
    
    // Don't forget to free memory when done
    for (int i = 0; i < num_layers; i++) {
        free(net->layers[i].neurons);
    }
    free(net->layers);
    free(net);
    
    return 0;
}
