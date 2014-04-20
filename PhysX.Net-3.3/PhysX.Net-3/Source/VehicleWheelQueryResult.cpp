#include "StdAfx.h"
#include "VehicleWheelQueryResult.h"

VehicleWheelQueryResult^ VehicleWheelQueryResult::ToManaged(PxWheelQueryResult* unmanaged)
{
	auto managed = gcnew VehicleWheelQueryResult();

	managed->SuspensionLineStart = MathUtil::PxVec3ToVector3(unmanaged->suspLineStart);
	managed->SuspensionLineDirection = MathUtil::PxVec3ToVector3(unmanaged->suspLineDir);
	managed->SuspensionLineLength = unmanaged->suspLineLength;
	managed->IsInAir = unmanaged->isInAir;
	// TODO: Could be NULL
	managed->TireContactActor = ObjectTable::GetObject<Actor^>((intptr_t)unmanaged->tireContactActor);
	// TODO: Could be NULL
	managed->TireContactShape = ObjectTable::GetObject<Shape^>((intptr_t)unmanaged->tireContactShape);
	// TODO: Could be NULL
	managed->TireSurfaceMaterial = ObjectTable::GetObject<Material^>((intptr_t)unmanaged->tireSurfaceMaterial);
	managed->TireSurfaceType = unmanaged->tireSurfaceType;
	managed->TireContactPoint = MathUtil::PxVec3ToVector3(unmanaged->tireContactPoint);
	managed->TireContactNormal = MathUtil::PxVec3ToVector3(unmanaged->tireContactNormal);
	managed->TireFriction = unmanaged->tireFriction;
	managed->SuspensionJounce = unmanaged->suspJounce;
	managed->SuspensionSpringForce = unmanaged->suspSpringForce;
	managed->TireLongitudinalDirection = MathUtil::PxVec3ToVector3(unmanaged->tireLongitudinalDir);
	managed->TireLateralDirection = MathUtil::PxVec3ToVector3(unmanaged->tireLateralDir);
	managed->LongitudinalSlip = unmanaged->longitudinalSlip;
	managed->LateralSlip = unmanaged->lateralSlip;
	managed->SteerAngle = unmanaged->steerAngle;
	managed->LocalPose = MM(&unmanaged->localPose);

	return managed;
}