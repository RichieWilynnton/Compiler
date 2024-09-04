#ifndef VARLIT_H
#define VARLIT_H

#include "../Exp.h"
#include "../DataType.h"

#include <string>
#include <memory>

class VarLit : public Exp {
    public:
        std::string name;
        
        VarLit(std::string name, DataType::DataType type); // defined in cpp

        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> clone() override;

};

#endif