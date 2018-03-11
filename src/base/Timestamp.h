#ifndef __INET_TIMESTAMP_H
#define __INET_TIMESTAMP_H

#include <stdint.h>
#include <cstdlib>
#include <string>
#include <cinttypes>

namespace inet
{
    class Timestamp
    {
        public:
            Timestamp();

            explicit Timestamp(int64_t microSecondSinceEpoch);

            bool valid() const
            {
                return microSecondSinceEpoch_ > 0;
            }

            int64_t microSecondSinceEpoch() const
            {
                return microSecondSinceEpoch_;
            }

            std::string toReadString() const;

            std::string toString() const;

            static Timestamp now();

            static Timestamp invalid();

            static const int kMicroSecondPerSecond;
        
        private:
            int64_t microSecondSinceEpoch_;
    };

    inline bool operator<(const Timestamp& lhs, const Timestamp& rhs)
    {
        return lhs.microSecondSinceEpoch() < rhs.microSecondSinceEpoch();
    }

    inline bool operator==(const Timestamp& lhs, const Timestamp& rhs)
    {
        return lhs.microSecondSinceEpoch() == rhs.microSecondSinceEpoch();
    }

    inline Timestamp addTime(Timestamp timestamp, double seconds)
    {
        int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondPerSecond);
        return Timestamp(timestamp.microSecondSinceEpoch() + delta);
    }
}

#endif
