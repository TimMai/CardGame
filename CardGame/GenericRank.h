#pragma once

#include <string>
#include <vector>

class GenericRank {
public:
    virtual ~GenericRank() = 0;
    virtual std::string ToString() const = 0;

    void SetValue(int val) { Value = val; }
    int GetValue() const { return Value; }
protected:
    int Value;
};


class GenericRankPackage {
public:
    virtual ~GenericRankPackage() {}

    int GetNumOfRanks() const { return RankCollection.size(); };
    std::vector<const GenericRank*> GetRanks() const {
        std::vector<const GenericRank*> Ranks;

        for (int i = 0; i < RankCollection.size(); i++) {
            const GenericRank* Rank = (const GenericRank*)RankCollection[i];
            Ranks.push_back(Rank);
        }

        return Ranks;
    }

    void SetRankValue(const GenericRank* Rank, int val) {
        for (int i = 0; i < RankCollection.size(); i++) {
            if (RankCollection[i] == Rank) {
                RankCollection[i]->SetValue(val);
                break;
            }
        }
    }

protected:
    std::vector<GenericRank*> RankCollection;
};
