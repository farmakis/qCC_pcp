
#include <Partition.h>

using namespace PCP;

int Partition::labelCutPursuitComponents(CCCoreLib::GenericIndexedCloudPersist* theCloud,
										int32_t knn,
										double knnRadius,
										int32_t N,
										int32_t D,
										const std::vector<float>& Y,
										float regularization,
										float spatialWeight,
										int32_t cutoff,
										std::vector<int32_t>& components,
										CCCoreLib::GenericProgressCallback* progressCb,
										CCCoreLib::DgmOctree* theOctree)
{
	if (nullptr == theCloud)
	{
		return -1;
	}

	// we use the default scalar field to store components labels
	if (!theCloud->enableScalarField())
	{
		// failed to enable a scalar field
		return -1;
	}

	// instantiate the graph and compute edges
	Graph G(N, theCloud, theOctree);
	G.computeEdges(knn, knnRadius, progressCb);

	// call cut pursuit
	auto rV = G.partitionCutPursuit(D,
									Y,
									components,
									regularization,
									spatialWeight,
									cutoff,
									0.01f, 15, 2, 2, 0.7f, 3, 3, 1000,
									false, true, true, false,
									-1,
									progressCb);

	return rV;
}
