// Probability Density Function interface class
// Written by Sergey Kosov in 2015 for Project X
#pragma once

#include "BaseRandomModel.h"

namespace DirectGraphicalModels 
{
	// ================================ PDF Class ==============================
	/**
	 * @brief Interface class for Probability Density Function (PDF)
	 * @details This class defines the interface for estimation of probability density functions for
	 * random read-valued variables
	 * @todo Add smooth() method
	 * @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/	
	class IPDF : public CBaseRandomModel 
	{
	friend class CTrainNodeBayes;
	
	public:
		DllExport IPDF(void) : CBaseRandomModel(0), m_nPoints(0) {}
		DllExport virtual ~IPDF(void) = default;

		/**
		 * @brief Adds a sample point for PDF estimation.
		 * @param point The sample point.
		 */
		DllExport virtual void		addPoint(Scalar point) = 0;
		/**
		 * @brief Returns the probability density value for the argument \b point.
		 * @param point The sample point.
		 * @returns The corresponding probaility density value.
		 */
		DllExport virtual double	getDensity(Scalar point) = 0;
		/**
		 * @brief Performs the gaussian smoothing on the histogram
		 * @details Performs \b nIt iterations of gaussian smothing of the histograms in order to overcome the "over-fitting" problem
		 * @param nIt Number of iterations
		 */
		DllExport virtual void		smooth(unsigned int nIt = 1) = 0;
		/**
		 * @brief Returns the lower argument boundary of the PDF
		 * @returns The lower bound
		 */
		DllExport virtual Scalar	min(void) const = 0;
		/**
		 * @brief Returns the upper argument boundary of the PDF
		 * @returns The upper bound
		 */
		DllExport virtual Scalar	max(void) const = 0;
		/**
		 * @brief Checks weather the PDF was estimated.
		 * @retval true if at least one sample was added with the addPoint() function.
		 * @retval false otherwise
		 */
		DllExport bool				isEstimated(void) { return m_nPoints != 0; }

	
	protected:
		long	m_nPoints;				///< The number of samples, added with the addPoint() function
	};

	using ptr_pdf_t = std::shared_ptr<IPDF>;
}
