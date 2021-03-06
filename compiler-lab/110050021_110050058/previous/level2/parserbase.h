// Generated by Bisonc++ V2.09.03 on Tue, 25 Feb 2014 04:12:39 +0530

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <vector>
#include <iostream>


namespace // anonymous
{
    struct PI__;
}


class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
    enum Tokens__
    {
        INTEGER_NUMBER = 257,
        BB,
        FLOAT_NUMBER,
        NAME,
        RETURN,
        INTEGER,
        FLOAT,
        DOUBLE,
        IF,
        ELSE,
        GOTO,
        ASSIGN_OP,
        NE,
        EQ,
        LT,
        LE,
        GT,
        GE,
    };

// $insert STYPE
union STYPE__
{
 int integer_value;
 float float_value;
 double double_value;
 std::string * string_value;
 list<Ast *> * ast_list;
 Ast * ast;
 Symbol_Table * symbol_table;
 Symbol_Table_Entry * symbol_entry;
 Basic_Block * basic_block;
 list<Basic_Block *> * basic_block_list;
 Procedure * procedure;
};


    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


