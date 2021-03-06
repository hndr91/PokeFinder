#include "FrameValidator.hpp"

FrameValidator::FrameValidator(QObject *parent) : QValidator(parent)
{

}

void FrameValidator::fixup(QString & input) const
{
    input.remove(QRegExp("[^0-9]"));
    uint32_t temp = input.toUInt(NULL, 10);
    if(temp > UINT32_MAX)
    {
        input.remove(input.length() - 1, 1);
    }
}

QValidator::State FrameValidator::validate(QString & input, int & pos) const
{
    bool pass;
    uint32_t frame = input.toUInt(&pass, 10);
    (void) pos;

    if (input == "")
    {
        return QValidator::Acceptable;
    }
    else if (!pass)
    {
        return QValidator::Invalid;
    }
    else if(frame > UINT32_MAX)
    {
        return QValidator::Invalid;
    }

    return QValidator::Acceptable;
}
