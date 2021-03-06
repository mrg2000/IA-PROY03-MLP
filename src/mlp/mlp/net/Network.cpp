#include <mlp/net/Network.h>


Network::Network (const NetworkSettings& settings) : settings(settings) {}

void Network::train (const Network::Matrix& input, const Network::Matrix& target) {
    for (size_t epoch = 0; epoch < settings.epochs; ++epoch) {
        if (this->early_stop()) {
            break;
        }
        this->forward(input);
        this->backward(target);
        this->on_epoch_callback(epoch);
    }
}

void Network::on_epoch_callback (size_t) {}

bool Network::early_stop () {
    return false;
}


