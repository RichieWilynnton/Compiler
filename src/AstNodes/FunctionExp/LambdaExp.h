// #pragma once
// #include "../Exp.h"
// #include "../Block.h"
// #include <string>
// #include <unordered_map>
// #include <memory>

// class LambdaExp : public Exp {
//     public:
//         std::unique_ptr<Block> funcBody;
//         std::vector<std::pair<std::string, DataType::DataType>> params;


//         LambdaExp(std::unique_ptr<Exp>& exp) : exp(std::move(exp)) {inferType();}
//         std::string genCode() override;
//         std::string printNode() override; 
//         void inferType() override;
// };