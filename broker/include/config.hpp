#pragma once

#include <string>
#include <map>

enum class QueueOrder {
    FIFO,
    NO,
};

enum class Durability {
    MEMORY,
    DISK,
};

struct Queue {
    std::string name;
    Durability durability;
    QueueOrder order;
    int message_ttl = -1;  // -1 означает "без ограничений"
};

struct Config {
    std::map<std::string, Queue> queues;

    static Config fromFile(const std::string& path);
};