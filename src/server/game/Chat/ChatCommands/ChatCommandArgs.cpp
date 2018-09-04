/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ChatCommandArgs.h"
#include "ChatCommand.h"
#include "ChatCommandHyperlinks.h"
#include "ObjectMgr.h"

using namespace Trinity::ChatCommands;

struct GameTeleVisitor
{
    using value_type = GameTele const*;
    value_type operator()(Hyperlink<tele> tele) const { return sObjectMgr->GetGameTele(tele); }
    value_type operator()(std::string const& tele) const { return sObjectMgr->GetGameTele(tele); }
};
char const* Trinity::ChatCommands::ArgInfo<GameTele const*>::tryConsume(GameTele const*& data, char const* args)
{
    Variant<Hyperlink<tele>, std::string> val;
    if ((args = CommandArgsConsumerSingle<decltype(val)>::tryConsumeTo(val, args)))
        data = boost::apply_visitor(GameTeleVisitor(), val);
    return args;
}
