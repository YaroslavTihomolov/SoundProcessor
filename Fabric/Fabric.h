/*
//
// Created by я on 24.11.2022.
//

#ifndef SOUNDPROCESSOR_FABRIC_H
#define SOUNDPROCESSOR_FABRIC_H

#include <unordered_map>
#include <string>

class converter;

typedef converter*(*converterInstanceGenerator)();

class TheConverterFactory {
public:
    static TheConverterFactory& Instance()
    {
        static TheConverterFactory theSingleInstance;
        return theSingleInstance;
    }

    void RegisterConverter(const std::string, const converterInstanceGenerator&);
    converter* CreateConverter(std::string);

private:
    std::unordered_map <std::string, converterInstanceGenerator> converts;
    TheConverterFactory(){}
    TheConverterFactory(const TheConverterFactory& root) = delete;
    TheConverterFactory& operator=(const TheConverterFactory) = delete;
};


#endif //SOUNDPROCESSOR_FABRIC_H
*/
#ifndef SOUNDPROCESSOR_FABRIC_H
#define SOUNDPROCESSOR_FABRIC_H

#include <map>
#include <string>
#include <memory>

template<class ID, class Base>
class GenericObjectFactory {
private:
    GenericObjectFactory() {}
    GenericObjectFactory(const GenericObjectFactory& other) = delete;
    GenericObjectFactory& operator=(const GenericObjectFactory&) = delete;

    typedef std::shared_ptr<Base> (*fInstantiator)();

    template<class Derived>
    static std::shared_ptr<Base> instantiator() {
        return std::make_shared<Derived>();
    }

    std::map<ID, fInstantiator> classes;

public:
    template<class Derived>
    bool add(ID id) {
        classes[id] = &instantiator<Derived>;
        return true;
    }

    static GenericObjectFactory& Instance()
    {
        static GenericObjectFactory theSingleInstance;
        return theSingleInstance;
    }

    fInstantiator get(ID id) {
        return classes[id];
    }

};


/*#include <map>

class converter;

class ObjectFactory {
private:
    ObjectFactory() {}
    ObjectFactory(const ObjectFactory& other) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;

    typedef converter *(*fInstantiator)();

    template<class Derived>
    static converter *instantiator() {
        return new Derived();
    }

    std::map<std::string, fInstantiator> classes;

public:
    template<class Derived>
    bool add(const std::string& id) {
        classes[id] = &instantiator<Derived>;
        return true;
    }

    static ObjectFactory& Instance()
    {
        static ObjectFactory theSingleInstance;
        return theSingleInstance;
    }

    fInstantiator get(const std::string& id) {
        return classes[id];
    }

};*/

#endif //SOUNDPROCESSOR_FABRIC_H
