/*
 * DeciderUWBIREDSync.h
 * Author: Jerome Rousselot <jerome.rousselot@csem.ch>
 * Copyright: (C) 2008-2010 Centre Suisse d'Electronique et Microtechnique (CSEM) SA
 *              Wireless Embedded Systems
 *              Jaquet-Droz 1, CH-2002 Neuchatel, Switzerland.
 */

#ifndef UWBIREDSYNC_H_
#define UWBIREDSYNC_H_

#include "MiXiMDefs.h"
#include "Mapping.h"
#include "DeciderUWBIRED.h"

class PhyLayerUWBIR;
class Signal;

/**
 * @brief  this Decider models a non-coherent energy-detection receiver
 * that synchronizes on the first sync preamble sequence
 * that is "long enough" and "powerful enough". This is defined with
 * the respective fields tmin and syncThreshold.
 *
 * Citation of the following publication is appreciated if you use the MiXiM UWB PHY model
 * for a publication of your own.
 * J. Rousselot, J.-D. Decotignie, An ultra-wideband impulse radio PHY
 * layer model for network simulation. SIMULATION January 2011 vol. 87 no. 1-2 82-112.
 *
 * For more information, see also:
 *
 * [1] J. Rousselot, J.-D. Decotignie, An ultra-wideband impulse radio PHY
 * layer model for network simulation. SIMULATION January 2011 vol. 87 no.
 * 1-2 82-112. http://dx.doi.org/10.1177/0037549710377767
 * [2] J. Rousselot, Ultra Low Power Communication Protocols for UWB
 * Impulse Radio Wireless Sensor Networks. EPFL Thesis 4720, 2010.
 * http://infoscience.epfl.ch/record/147987
 * [3]  A High-Precision Ultra Wideband Impulse Radio Physical Layer Model
 * for Network Simulation, Jérôme Rousselot, Jean-Dominique Decotignie,
 * Second International Omnet++ Workshop,Simu'TOOLS, Rome, 6 Mar 09.
 * http://portal.acm.org/citation.cfm?id=1537714
 *
 * @ingroup ieee802154a
 * @ingroup decider
*/
class MIXIM_API DeciderUWBIREDSync: public DeciderUWBIRED {
public:
	DeciderUWBIREDSync(DeciderToPhyInterface* iface,
				PhyLayerUWBIR* _uwbiface,
				double _syncThreshold, bool _syncAlwaysSucceeds, bool _stats,
				bool _trace, double _tmin, bool alwaysFailOnDataInterference);
	~DeciderUWBIREDSync();

protected:
	virtual bool attemptSync(Signal* signal);
	bool evaluateEnergy(Signal* s);

private:
	simtime_t tmin;
	AirFrameVector syncVector;
	Argument argSync;
};

#endif /* UWBIREDSYNC_H_ */
