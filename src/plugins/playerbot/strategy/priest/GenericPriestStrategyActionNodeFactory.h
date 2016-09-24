#pragma once

namespace ai
{
    class GenericPriestStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
    {
    public:
        GenericPriestStrategyActionNodeFactory()
        {
            creators["inner fire"] = &inner_fire;
            creators["holy nova"] = &holy_nova;
            creators["power word: fortitude"] = &power_word_fortitude;
            creators["power word: fortitude on party"] = &power_word_fortitude_on_party;
            creators["divine spirit"] = &divine_spirit;
            creators["divine spirit on party"] = &divine_spirit_on_party;
            creators["power word: shield"] = &power_word_shield;
            creators["power word: shield on party"] = &power_word_shield_on_party;
            creators["renew"] = &renew;
            creators["renew on party"] = &renew_on_party;
            creators["greater heal"] = &greater_heal;
            creators["greater heal on party"] = &greater_heal_on_party;
            creators["heal"] = &heal;
            creators["heal on party"] = &heal_on_party;
            creators["lesser heal"] = &lesser_heal;
            creators["lesser heal on party"] = &lesser_heal_on_party;
            creators["flash heal"] = &flash_heal;
            creators["flash heal on party"] = &flash_heal_on_party;
            creators["psychic scream"] = &psychic_scream;
            creators["fade"] = &fade;
        }
    private:
        static ActionNode* inner_fire(PlayerbotAI* ai)
        {
            return new ActionNode ("inner fire",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* holy_nova(PlayerbotAI* ai)
        {
            return new ActionNode ("holy nova",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* power_word_fortitude(PlayerbotAI* ai)
        {
            return new ActionNode ("power word: fortitude",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* power_word_fortitude_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("power word: fortitude on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* divine_spirit(PlayerbotAI* ai)
        {
            return new ActionNode ("divine spirit",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* divine_spirit_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("divine spirit on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* power_word_shield(PlayerbotAI* ai)
        {
            return new ActionNode ("power word: shield",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("renew", 50.0f), NULL),
                /*C*/ NULL);
        }
        static ActionNode* power_word_shield_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("power word: shield on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("renew on party", 50.0f), NULL),
                /*C*/ NULL);
        }
        static ActionNode* renew(PlayerbotAI* ai)
        {
            return new ActionNode ("renew",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* renew_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("renew on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* greater_heal(PlayerbotAI* ai)
        {
            return new ActionNode ("greater heal",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("heal"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* greater_heal_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("greater heal on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("heal on party"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* heal(PlayerbotAI* ai)
        {
            return new ActionNode ("heal",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("lesser heal"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* heal_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("heal on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("lesser heal on party"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* lesser_heal(PlayerbotAI* ai)
        {
            return new ActionNode ("lesser heal",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* lesser_heal_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("lesser heal on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NULL,
                /*C*/ NULL);
        }
        static ActionNode* flash_heal(PlayerbotAI* ai)
        {
            return new ActionNode ("flash heal",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("greater heal"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* flash_heal_on_party(PlayerbotAI* ai)
        {
            return new ActionNode ("flash heal on party",
                /*P*/ NextAction::array(0, new NextAction("remove shadowform"), NULL),
                /*A*/ NextAction::array(0, new NextAction("greater heal on party"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* psychic_scream(PlayerbotAI* ai)
        {
            return new ActionNode ("psychic scream",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("fade"), NULL),
                /*C*/ NULL);
        }
        static ActionNode* fade(PlayerbotAI* ai)
        {
            return new ActionNode ("fade",
                /*P*/ NULL,
                /*A*/ NextAction::array(0, new NextAction("flee"), NULL),
                /*C*/ NULL);
        }
    };
};
