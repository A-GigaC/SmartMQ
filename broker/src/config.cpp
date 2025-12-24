#include "config.hpp"

#include <yaml-cpp/yaml.h>
#include <fstream>

namespace {

QueueOrder stringToQueueOrder(const std::string& str) {
    if (str == "FIFO") {
        return QueueOrder::FIFO;
    } else if (str == "NO") {
        return QueueOrder::NO;
    }
    throw std::runtime_error("Unknown queue order: " + str);
}

std::string queueOrderToString(QueueOrder order) {
    switch (order) {
        case QueueOrder::FIFO:
            return "FIFO";
        case QueueOrder::NO:
            return "NO";
    }
    return "NO";
}

Durability stringToDurability(const std::string& str) {
    if (str == "disk") {
        return Durability::DISK;
    } else if (str == "memory") {
        return Durability::MEMORY;
    }
    throw std::runtime_error("Unknown durability option: " + str);
}

}

Config Config::fromFile(const std::string& path) {
    YAML::Node config = YAML::LoadFile(path);
    Config result;
    if (config["queues"]) {
        for (const auto& node : config["queues"]) {
            Queue q;
            q.name = node["name"].as<std::string>();
            q.durability = stringToDurability(node["durability"].as<std::string>());
            q.order = stringToQueueOrder(node["order"].as<std::string>());
            if (node["message_ttl"]) {
                q.message_ttl = node["message_ttl"].as<int32_t>();
            }

            result.queues[q.name] = q;
        }
    }

    return result;
}