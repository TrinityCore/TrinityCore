#ifndef SOUTHPORT_POKER_REFUND_LEDGER_H
#define SOUTHPORT_POKER_REFUND_LEDGER_H

#include <cstdint>
#include <map>

namespace SouthportPoker
{
// A running hand is void on recovery. Keep each participant's balance from
// before the blinds, even after folding or leaving. Normal cash-outs reduce
// this claim; successful settlement replaces it with the final table stacks.
class RefundLedger
{
public:
    using Balances = std::map<std::uint64_t, std::uint64_t>;

    void BeginHand(Balances const& participants) { _claims = participants; }
    void Settle() { _claims.clear(); }

    void BuyIn(std::uint64_t guid, std::uint64_t amount)
    {
        auto it = _claims.find(guid);
        if (it != _claims.end())
            it->second += amount;
    }

    void CashOut(std::uint64_t guid, std::uint64_t amount)
    {
        auto it = _claims.find(guid);
        if (it != _claims.end())
            it->second -= amount;
    }

    Balances Recoverable(Balances const& seatedStacks) const
    {
        Balances result = seatedStacks;
        for (auto const& claim : _claims)
            result[claim.first] = claim.second;
        return result;
    }

private:
    Balances _claims;
};
}

#endif
