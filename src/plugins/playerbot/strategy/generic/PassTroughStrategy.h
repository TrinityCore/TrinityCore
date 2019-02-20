#pragma once

namespace ai
{
    class PassTroughStrategy : public Strategy
    {
    public:
        PassTroughStrategy(PlayerbotAI* ai, float relevance = 100.0f) : Strategy(ai), relevance(relevance) {}

        virtual void InitTriggers(std::list<TriggerNode*> &triggers)
        {
            for (list<string>::iterator i = supported.begin(); i != supported.end(); i++)
            {
                string s = i->c_str();

                triggers.push_back(new TriggerNode(
                    s, 
                    NextAction::array(0, new NextAction(s, relevance), NULL)));
            }
        }

    protected:
        list<string> supported;
        float relevance;
    };
}
