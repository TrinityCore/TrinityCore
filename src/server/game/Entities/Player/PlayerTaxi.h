#ifndef __PLAYERTAXI_H__
#define __PLAYERTAXI_H__

#include "DB2Stores.h"
#include "Define.h"
#include "WorldSession.h"
#include <map>

class TC_GAME_API PlayerTaxi
{
    public:
        PlayerTaxi() { m_taximask.fill(0); }
        ~PlayerTaxi() { }
        // Nodes
        void InitTaxiNodesForLevel(uint32 race, uint32 chrClass, uint8 level);
        void LoadTaxiMask(std::string const& data);

        bool IsTaximaskNodeKnown(uint32 nodeidx) const
        {
            uint8  field   = uint8((nodeidx - 1) / 8);
            uint32 submask = 1 << ((nodeidx-1) % 8);
            return (m_taximask[field] & submask) == submask;
        }
        bool SetTaximaskNode(uint32 nodeidx)
        {
            uint8  field   = uint8((nodeidx - 1) / 8);
            uint32 submask = 1 << ((nodeidx-  1) % 8);
            if ((m_taximask[field] & submask) != submask)
            {
                m_taximask[field] |= submask;
                return true;
            }
            else
                return false;
        }
        void AppendTaximaskTo(WorldPackets::Taxi::ShowTaxiNodes& data, bool all);
        TaxiMask const& GetTaxiMask() const { return m_taximask; }

        // Destinations
        bool LoadTaxiDestinationsFromString(std::string const& values, uint32 team);
        std::string SaveTaxiDestinationsToString();

        void ClearTaxiDestinations() { m_TaxiDestinations.clear(); }
        void AddTaxiDestination(uint32 dest) { m_TaxiDestinations.push_back(dest); }
        void SetTaxiDestination(std::vector<uint32>& nodes) { m_TaxiDestinations.clear(); m_TaxiDestinations.insert(m_TaxiDestinations.begin(), nodes.begin(), nodes.end()); }
        uint32 GetTaxiSource() const { return m_TaxiDestinations.empty() ? 0 : m_TaxiDestinations.front(); }
        uint32 GetTaxiDestination() const { return m_TaxiDestinations.size() < 2 ? 0 : m_TaxiDestinations[1]; }
        uint32 GetCurrentTaxiPath() const;
        uint32 NextTaxiDestination()
        {
            m_TaxiDestinations.pop_front();
            return GetTaxiDestination();
        }
        bool RequestEarlyLanding();
        std::deque<uint32> const& GetPath() const { return m_TaxiDestinations; }
        bool empty() const { return m_TaxiDestinations.empty(); }

        friend std::ostringstream& operator<< (std::ostringstream& ss, PlayerTaxi const& taxi);
    private:
        TaxiMask m_taximask;
        std::deque<uint32> m_TaxiDestinations;
};

std::ostringstream& operator << (std::ostringstream& ss, PlayerTaxi const& taxi);

#endif
