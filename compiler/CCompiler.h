//
// Created by rory on 2021/3/7.
//

#ifndef JUDGERTOTEACHING_CCOMPILER_H
#define JUDGERTOTEACHING_CCOMPILER_H
#include "Compiler.h"

class CCompiler : public Compiler {
public:
    explicit CCompiler(JudgeConfig* config);
    CompileResult compile() override;
private:

    string generateCompileCommand() const override;
};


#endif //JUDGERTOTEACHING_CCOMPILER_H
