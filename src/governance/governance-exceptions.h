// Public Resource ℗ 2021 Đ𝖺𝗌𝗁 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// Public Resource ℗ 2020 𝖠𝗆𝖾𝗋𝗈 𝖣𝖾𝗏𝖾𝗅𝗈𝗉𝖾𝗋𝗌
// THIS REPOSITORY IS LICENSED UNDER THE AMERO PUBLIC RESOURCE LICENSE.

#ifndef BITCOIN_GOVERNANCE_GOVERNANCE_EXCEPTIONS_H
#define BITCOIN_GOVERNANCE_GOVERNANCE_EXCEPTIONS_H

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

enum governance_exception_type_enum_t {
    /// Default value, normally indicates no exception condition occurred
    GOVERNANCE_EXCEPTION_NONE = 0,
    /// Unusual condition requiring no caller action
    GOVERNANCE_EXCEPTION_WARNING = 1,
    /// Requested operation cannot be performed
    GOVERNANCE_EXCEPTION_PERMANENT_ERROR = 2,
    /// Requested operation not currently possible, may resubmit later
    GOVERNANCE_EXCEPTION_TEMPORARY_ERROR = 3,
    /// Unexpected error (ie. should not happen unless there is a bug in the code)
    GOVERNANCE_EXCEPTION_INTERNAL_ERROR = 4
};

inline std::ostream& operator<<(std::ostream& os, governance_exception_type_enum_t eType)
{
    switch (eType) {
    case GOVERNANCE_EXCEPTION_NONE:
        os << "GOVERNANCE_EXCEPTION_NONE";
        break;
    case GOVERNANCE_EXCEPTION_WARNING:
        os << "GOVERNANCE_EXCEPTION_WARNING";
        break;
    case GOVERNANCE_EXCEPTION_PERMANENT_ERROR:
        os << "GOVERNANCE_EXCEPTION_PERMANENT_ERROR";
        break;
    case GOVERNANCE_EXCEPTION_TEMPORARY_ERROR:
        os << "GOVERNANCE_EXCEPTION_TEMPORARY_ERROR";
        break;
    case GOVERNANCE_EXCEPTION_INTERNAL_ERROR:
        os << "GOVERNANCE_EXCEPTION_INTERNAL_ERROR";
        break;
    }
    return os;
}

/**
 * A class which encapsulates information about a governance exception condition
 *
 * Derives from std::exception so is suitable for throwing
 * (ie. will be caught by a std::exception handler) but may also be used as a
 * normal object.
 */
class CGovernanceException : public std::exception
{
private:
    std::string strMessage;

    governance_exception_type_enum_t eType;

    int nNodePenalty;

public:
    explicit CGovernanceException(const std::string& strMessageIn = "",
        governance_exception_type_enum_t eTypeIn = GOVERNANCE_EXCEPTION_NONE,
        int nNodePenaltyIn = 0) :
        strMessage(),
        eType(eTypeIn),
        nNodePenalty(nNodePenaltyIn)
    {
        std::ostringstream ostr;
        ostr << eType << ":" << strMessageIn;
        strMessage = ostr.str();
    }

    ~CGovernanceException() noexcept override = default;

    const char* what() const noexcept override
    {
        return strMessage.c_str();
    }

    const std::string& GetMessage() const
    {
        return strMessage;
    }

    governance_exception_type_enum_t GetType() const
    {
        return eType;
    }

    int GetNodePenalty() const
    {
        return nNodePenalty;
    }
};

#endif // BITCOIN_GOVERNANCE_GOVERNANCE_EXCEPTIONS_H
