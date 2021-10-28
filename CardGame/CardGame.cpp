#include <stdio.h>
#include "RandomCardGenerator.h"
#include "EuropeanSuites.h"

int main() {
#if 0
    RandomCardGenerator generator;

    for (int i = 0; i < 52; i++) {
        Card card = generator.GetUniqueRandomCard();
        printf("Suite: %d, Rank: %d\n", card.GetSuite(), card.GetRank());
    }
#endif
    EuropeanSuitePackage euro;

    std::vector<const GenericSuite*> suites = euro.GetSuites();

    for (int i = 0; i < suites.size(); i++) {
        printf("%d\n", suites[i]->GetValue());
        euro.SetSuiteValue(suites[i], 5);
        printf("%s\n", suites[i]->ToString().c_str());
    }

    return 0;
}
