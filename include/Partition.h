/*=============================================================================
 * Partition class for CloudCompare (Ioannis Farmakis, 2026)
 *
 * Provides point cloud partitioning/segmentation based on the Parallel Cut
 * Pursuit algorithm, built on top of the Graph and CP classes of this
 * library.
 *
 * Reference:
 * Hugo Raguet and Loic Landrieu, 2019, "Parallel Cut Pursuit for
 * Minimization of the Graph Total Variation"
 * (https://doi.org/10.48550/arXiv.1905.02316).
 *===========================================================================*/
#pragma once

// system
#include <cstdint>
#include <vector>

// Local
#include <Graph.h>

namespace PCP
{
	//! Point cloud partitioning algorithms based on the Parallel Cut Pursuit method
	class Partition
	{
	  public:
		//! Partitions a point cloud using the Parallel Cut Pursuit algorithm
		/** The algorithm is described in Hugo Raguet and Loic Landrieu, 2019 paper
		    titled "Parallel Cut Pursuit for Minimization of the Graph Total Variation"
		    (https://doi.org/10.48550/arXiv.1905.02316).
		    \param theCloud the point cloud to label
		    \param knn the maximum number of neighbors to search for each point (k)
		    \param knnRadius the maximum distance to search for neighbors (in the same unit as the point cloud coordinates)
		    \param N the number of points in the cloud
		    \param D the number of dimensions for the feature space
		    \param Y the feature matrix (size N * D, row-major)
		    \param regularization the regularization parameter for the cut pursuit algorithm
		    \param spatialWeight the weight for spatial coordinates in the feature space
		    \param cutoff the minimum component weight for the cut pursuit algorithm
		    \param components an array to store the component assignments for each point (size should be equal to the number of points in the cloud)
		    \param progressCb the client application can get some notification of the process progress through this callback mechanism
		    \param theOctree the cloud octree if it has already been computed
		    \return the number of components (>= 0) or an error code (< 0)
		**/
		static int labelCutPursuitComponents(CCCoreLib::GenericIndexedCloudPersist* theCloud,
		                                     int32_t                                knn,
		                                     double                                 knnRadius,
		                                     int32_t                                N,
		                                     int32_t                                D,
		                                     const std::vector<float>&              Y,
		                                     float                                  regularization,
		                                     float                                  spatialWeight,
		                                     int32_t                                cutoff,
		                                     std::vector<int32_t>&                  components,
		                                     CCCoreLib::GenericProgressCallback*    progressCb = nullptr,
		                                     CCCoreLib::DgmOctree*                  theOctree  = nullptr);
	};
} // namespace PCP
