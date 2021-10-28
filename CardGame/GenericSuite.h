#pragma once

#include <string>
#include <vector>

class GenericSuite {
public:
    virtual ~GenericSuite() {}
    virtual std::string ToString() const = 0;

    void SetValue(int val) { Value = val; }
    int GetValue() const { return Value; }

protected:
    int Value;
};

class GenericSuitePackage {
public:
    virtual ~GenericSuitePackage() {}

    int GetNumOfSuites() const { return SuiteCollection.size(); }
    std::vector<const GenericSuite*> GetSuites() {
        std::vector<const GenericSuite*> Suites;

        for (int i = 0; i < SuiteCollection.size(); i++) {
            const GenericSuite* Suite = (GenericSuite*)SuiteCollection[i];
            Suites.push_back(Suite);
        }

        return Suites;
    }

    void SetSuiteValue(const GenericSuite* Suite, int val) {
        for (int i = 0; i < SuiteCollection.size(); i++) {
            if (SuiteCollection[i] == Suite) {
                SuiteCollection[i]->SetValue(val);
                break;
            }
        }
    }
protected:
    std::vector<GenericSuite*> SuiteCollection;
};
