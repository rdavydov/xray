#ifndef _MPxTransform
#define _MPxTransform
//
//-
// ==========================================================================
// Copyright (C) Alias Systems Corp., and/or its licensors ("Alias").  
// All rights reserved.  These coded instructions, statements, computer  
// programs, and/or related material (collectively, the "Material")
// contain unpublished information proprietary to Alias, which is
// protected by Canadian and US federal copyright law and by international
// treaties. This Material may not be disclosed to third parties, or be copied
// or duplicated, in whole or in part, without the prior written consent of
// Alias.  ALIAS HEREBY DISCLAIMS ALL WARRANTIES RELATING TO THE MATERIAL,
// INCLUDING, WITHOUT LIMITATION, ANY AND ALL EXPRESS OR IMPLIED WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT SHALL ALIAS BE LIABLE FOR ANY DAMAGES WHATSOEVER, WHETHER DIRECT,
// INDIRECT, SPECIAL, OR PUNITIVE, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, OR IN EQUITY, ARISING OUT OF OR RELATED TO THE
// ACCESS TO, USE OF, OR RELIANCE UPON THE MATERIAL.
// ==========================================================================
//+
//
// CLASS DESCRIPTION (MPxTransform)
// 
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/MPxNode.h>
#include <maya/MObjectArray.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MPxTransformationMatrix.h>
#include <maya/MFnTransform.h>

// *****************************************************************************

// DECLARATIONS
 
class MDagPath;
class MMatrix;
class MVector;
class MPoint;
class MDGContext;
class MQuaternion;
class MEulerRotation;
class MBoundingBox;

// *****************************************************************************

// CLASS DECLARATION (MPxTransform)

/// Base class for user defined transforms (OpenMaya)
/**
  Create user defined locators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MPxTransform : public MPxNode  
{
public:
    ///
	MPxTransform();
	///
	MPxTransform(MPxTransformationMatrix *);
    ///
	virtual ~MPxTransform();
	///
	virtual	void	postConstructor();
	///                     
	virtual MPxNode::Type type() const;

	///
	virtual MPxTransformationMatrix *createTransformationMatrix();

	///
	virtual bool			isBounded() const;
	///	
	virtual MBoundingBox	boundingBox() const;

	///
	const MPxTransformationMatrix &transformationMatrix() const;
	///
	virtual void  resetTransformation (const MMatrix &);
	///
	virtual void  resetTransformation (MPxTransformationMatrix *);
	///
	virtual MStatus	compute(const MPlug& plug, MDataBlock& data);
	///
	virtual MStatus computeLocalTransformation (MPxTransformationMatrix *, 
												MDataBlock &);
	///
	virtual MStatus	clearLimits();
	///
	bool    isLimited(MFnTransform::LimitType type,
					  MStatus * ReturnStatus = NULL ) const;
	///
	double	limitValue (MFnTransform::LimitType type,
						MStatus * ReturnStatus = NULL ) const;
	///
	MStatus setLimit ( MFnTransform::LimitType type, double value);
	///
	MStatus enableLimit ( MFnTransform::LimitType type, bool flag);
	

	//  Method to validate input data.
	//
	///
	virtual MStatus	validateAndSetValue(const MPlug&,
										const MDataHandle&,
										const MDGContext&);
	//	Matrix methods
	//
	///
	virtual MMatrix getMatrix (const MDGContext& = MDGContext::fsNormal,
							   MStatus *ReturnStatus = NULL);
	///
	virtual MMatrix getMatrixInverse (const MDGContext& = MDGContext::fsNormal,
									  MStatus *ReturnStatus = NULL);


	//	Translation methods
	//
	///
	virtual MVector getTranslation(MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MStatus	translateTo(const MVector&, 
								MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus translateBy(const MVector&, 
								MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal);

	//	Rotation methods
	//
	///
	virtual MQuaternion getRotation(MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MEulerRotation getEulerRotation(MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MStatus	rotateTo(const MQuaternion&, 
								MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus rotateBy(const MQuaternion&, 
								MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus	rotateTo(const MEulerRotation&, 
								MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus rotateBy(const MEulerRotation&, 
							 MSpace::Space = MSpace::kTransform, 
							 const MDGContext& = MDGContext::fsNormal);

	//	Scale methods
	//
	///
	virtual MVector getScale(MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal,
							MStatus *ReturnStatus = NULL);
	///
	virtual MStatus	scaleTo(const MVector&, 
							MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus scaleBy(const MVector&, 
							MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal);

	//	Shear methods
	//
	///
	virtual MVector getShear(MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal,
							MStatus *ReturnStatus = NULL);
	///
	virtual MStatus	shearTo(const MVector&, 
							MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus shearBy(const MVector&, 
							MSpace::Space = MSpace::kTransform, 
							const MDGContext& = MDGContext::fsNormal);

	//	Pivot methods
	//
	///
	virtual MPoint	getScalePivot(MSpace::Space = MSpace::kTransform,	
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MPoint	getRotatePivot(MSpace::Space = MSpace::kTransform, 
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MVector	getScalePivotTranslation(MSpace::Space = MSpace::kTransform,
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MVector	getRotatePivotTranslation(MSpace::Space = 
								MSpace::kTransform,
								const MDGContext& = MDGContext::fsNormal,
								MStatus *ReturnStatus = NULL);
	///
	virtual MStatus	setScalePivot(const MPoint &,
									MSpace::Space = MSpace::kTransform,
									bool balance = true,
									const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus	setScalePivotTranslation(const MVector &,
									MSpace::Space = MSpace::kTransform,
									const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus	setRotatePivot(const MPoint &,
									MSpace::Space = MSpace::kTransform,
									bool balance = true,
									const MDGContext& = MDGContext::fsNormal);
	///
	virtual MStatus	setRotatePivotTranslation(const MVector &,
									MSpace::Space = MSpace::kTransform,
									const MDGContext& = MDGContext::fsNormal);


	//  Rotation order methods
	//
	virtual MTransformationMatrix::RotationOrder 
					getRotationOrder(const MDGContext&apiContext = 
									 MDGContext::fsNormal);
	///
	virtual	MStatus setRotationOrder(MTransformationMatrix::RotationOrder ro,
									 bool reorder = true, 
									 const MDGContext& apiContext 
									 = MDGContext::fsNormal);

	//  Rotation orientation methods
	//
	///
	virtual MQuaternion getRotateOrientation(MSpace::Space apiSpace
										 	= MSpace::kTransform, 
										 	const MDGContext&apiContext 
										 	= MDGContext::fsNormal,
											MStatus *ReturnStatus = NULL);
	///
	virtual MStatus setRotateOrientation(const MQuaternion &q, 
											MSpace::Space apiSpace 
											= MSpace::kTransform, 
											bool balance = true, 
											const MDGContext&apiContext 
											= MDGContext::fsNormal);
	///
	void updateMatrixAttrs(const MDGContext& apiContext = MDGContext::fsNormal);
	///
	MStatus updateMatrixAttrs(MObject &attr, 
							  const MDGContext &context = MDGContext::fsNormal);
	///
	static void mustCallValidateAndSet(MObject &);

	///
	static MStatus	setNonAffineMatricesEnabled(bool);
	///
	static bool isNonAffineMatricesEnabled(MStatus *ReturnStatus);
protected:
	//
	//	Methods for clamping and locking enforcement
	//
	///
	virtual MVector	applyTranslationLimits(const MVector &unclampedT,
									 MDataBlock &block,
									 MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyTranslationLocks(const MVector &toTest,
									const MVector &savedT,
									MStatus *ReturnStatus = NULL);
	///
	virtual MEulerRotation	applyRotationLimits(const MEulerRotation &unclampedR,
										  MDataBlock &block,
										  MStatus *ReturnStatus = NULL);
	///
	virtual	MEulerRotation applyRotationLocks(const MEulerRotation &toTest,
										const MEulerRotation &savedR,
										MStatus *ReturnStatus = NULL);
	///
	virtual MVector	applyScaleLimits(const MVector &unclampedS,
							   MDataBlock &block,
							   MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyScaleLocks(const MVector &toTest,
							  const MVector &savedS,
							  MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyShearLocks(const MVector &toTest,
							  const MVector &savedSh,
							  MStatus *ReturnStatus = NULL);
	///
	virtual	MEulerRotation applyRotateOrientationLocks(const MEulerRotation &toTest,
										const MEulerRotation &savedRO,
										MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyScaleLocksPivot(const MPoint &toTest,
							  		const MPoint &savedSP,
							  		MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyRotatePivotLocks(const MPoint &toTest,
							  		const MPoint &savedRP,
							  		MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyScaleLocksPivotTranslate(const MVector &toTest,
							  		const MVector &savedSPT,
							  		MStatus *ReturnStatus = NULL);
	///
	virtual	MVector applyRotatePivotLocksTranslate(const MVector &toTest,
							  		const MVector &savedRPT,
							  		MStatus *ReturnStatus = NULL);
	//
	//	Methods for marking the matrix dirty.
	//

	///
	MStatus dirtyMatrix();
	///
	MStatus	dirtyTranslation(const MVector &);
	///
	MStatus	dirtyRotation(const MEulerRotation &);
	///
	MStatus dirtyScale(const MVector &);
	///
	MStatus dirtyShear(const MVector &);
	///
	MStatus dirtyRotateOrientation(const MEulerRotation &);
	///
	MStatus dirtyScalePivot(const MPoint &);
	///
	MStatus dirtyRotatePivot(const MPoint &);
	///
	MStatus dirtyScalePivotTranslation(const MVector &);
	///
	MStatus dirtyRotatePivotTranslation(const MVector &);

	//
	//	checkAndSet methods. These are called by the compute method.
	//
	///
	virtual	MStatus	checkAndSetTranslation(MDataBlock &block,
										   const MPlug&, 
										   const MVector&, 
										   MSpace::Space = MSpace::kTransform);
	///
	virtual	MStatus checkAndSetRotation(MDataBlock &block,
										const MPlug&,
										const MEulerRotation&, 
										MSpace::Space = MSpace::kTransform);
	///
	virtual	MStatus checkAndSetScale(MDataBlock &block,
									 const MPlug&,
									 const MVector&, 
									 MSpace::Space = MSpace::kTransform);
	///
	virtual	MStatus checkAndSetShear(MDataBlock &block,
									 const MPlug&,
									 const MVector&, 
									 MSpace::Space = MSpace::kTransform);
	///
	virtual	MStatus checkAndSetRotateOrientation(MDataBlock &block,
											   const MPlug&, 
											   const MEulerRotation&, 
											   MSpace::Space 
											   = MSpace::kTransform,
											   bool balance = true);
	///
	virtual	MStatus	checkAndSetRotatePivot(MDataBlock &,
										   const MPlug&, 
										   const MPoint&, 
										   MSpace::Space = MSpace::kTransform, 
										   bool balance = true);
	///
	virtual	MStatus checkAndSetRotatePivotTranslation(MDataBlock &, 
													  const MPlug&, 
													  const MVector&, 
													  MSpace::Space = 
													  MSpace::kTransform);
	///
	virtual	MStatus	checkAndSetScalePivot(MDataBlock &,
										  const MPlug&,
										  const MPoint&, 
										  MSpace::Space = MSpace::kTransform,
										  bool = true);
	///
	virtual	MStatus checkAndSetScalePivotTranslation(MDataBlock &,
													 const MPlug&,
													 const MVector&, 
													 MSpace::Space = 
													 MSpace::kTransform);

public:
	// Default attributes.
	///	bounding box attribute
	static MObject nodeBoundingBox;
		///	bounding box minimum point
		static MObject nodeBoundingBoxMin;
			///	X component of nodeBoundingBoxMin
			static MObject nodeBoundingBoxMinX;
			///	Y component of nodeBoundingBoxMin
			static MObject nodeBoundingBoxMinY;
			///	Z component of nodeBoundingBoxMin
			static MObject nodeBoundingBoxMinZ;
		///	bounding box maximum point
		static MObject nodeBoundingBoxMax;
			///	X component of nodeBoundingBoxMax
			static MObject nodeBoundingBoxMaxX;
			///	Y component of nodeBoundingBoxMax
			static MObject nodeBoundingBoxMaxY;
			/// Z component of nodeBoundingBoxMax
			static MObject nodeBoundingBoxMaxZ;
		/// bounding box size vector
		static MObject nodeBoundingBoxSize;
			///	X component of nodeBoundingBoxSize
			static MObject nodeBoundingBoxSizeX;
			///	Y component of nodeBoundingBoxSize
			static MObject nodeBoundingBoxSizeY;
			///	Z component of nodeBoundingBoxSize
			static MObject nodeBoundingBoxSizeZ;
	/// object center attribute
	static MObject center;
		///	X component of the bounding box center
		static MObject boundingBoxCenterX;
		/// Y component of the bounding box center
		static MObject boundingBoxCenterY;
		/// Z component of the bounding box center
		static MObject boundingBoxCenterZ;

	/// matrix attribute
	static MObject matrix;
	/// inverse matrix attribute
	static MObject inverseMatrix;
	/// world matrix attribute
	static MObject worldMatrix;
	///Inverse world matrix attribute
	static MObject worldInverseMatrix;
	///Parent matrix attribute
	static MObject parentMatrix;
	///Inverse parent matrix attribute
	static MObject parentInverseMatrix;
	///Visibility attribute
	static MObject visibility;
	///Intermediate object attribute
	static MObject intermediateObject;
	///Template attribute
	static MObject isTemplated;
	///Ghosting attribute
	static MObject ghosting;
	///Instances object group info attribute
	static MObject instObjGroups;
		///Object groups attributes
		static MObject objectGroups;
			///Component in object groups attribute
			static MObject objectGrpCompList;
			///Group id attribute
			static MObject objectGroupId;
			///Group id attribute
			static MObject objectGroupColor;
	///Controls choice of wireframe dormant object color 
	static MObject useObjectColor;
	///The per object dormant wireframe color
	static MObject objectColor;

	///
	static MObject drawOverride;
	///
	static MObject overrideDisplayType;
	///
	static MObject overrideLevelOfDetail;
	///
	static MObject overrideShading;
	///
	static MObject overrideTexturing;
	///
	static MObject overridePlayback;
	///
	static MObject overrideEnabled;
	///
	static MObject overrideVisibility;
	///
	static MObject overrideColor;
	///
	static MObject lodVisibility;
	///
	static MObject renderInfo;
	///
	static MObject identification;
	///
	static MObject layerRenderable;
	///
	static MObject layerOverrideColor;

	///	translate attribute
	static MObject translate;
		///	translateX attribute
		static MObject translateX;
		///	translateY attribute
		static MObject translateY;
		///	translateZ attribute
		static MObject translateZ;
	///	rotate attribute
	static MObject rotate;
		///	rotateX attribute
		static MObject rotateX;
		///	rotateY attribute
		static MObject rotateY;
		///	rotateZ attribute
		static MObject rotateZ;
	///Rotate order attribute
	static MObject rotateOrder;
	///	scale attribute
	static MObject scale;
		///	scaleX attribute
		static MObject scaleX;
		///	scaleY attribute
		static MObject scaleY;
		///	scaleZ attribute
		static MObject scaleZ;
	static MObject shear;
		///	shearXY attribute
		static MObject shearXY;
		///	shearXZ attribute
		static MObject shearXZ;
		///	shearYZ attribute
		static MObject shearYZ;
	///	rotate pivot attribute
	static MObject rotatePivot;
		///	rotate pivot X attribute
		static MObject rotatePivotX;
		///	rotate pivot Y attribute
		static MObject rotatePivotY;
		///	rotate pivot Z attribute
		static MObject rotatePivotZ;
	///	rotate pivot translate attribute
	static MObject rotatePivotTranslate;
		///	rotate pivot translate X attribute
		static MObject rotatePivotTranslateX;
		///	rotate pivot translate Y attribute
		static MObject rotatePivotTranslateY;		
		///	rotate pivot translate Z attribute
		static MObject rotatePivotTranslateZ;
	///	scale pivot attribute
	static MObject scalePivot;
		///	scale pivot X attribute
		static MObject scalePivotX;
		///	scale pivot Y attribute
		static MObject scalePivotY;
		///	scale pivot Z attribute
		static MObject scalePivotZ;
	///Scale pivot translate attribute
	static MObject scalePivotTranslate;
		///	scale pivot translate X attribute
		static MObject scalePivotTranslateX;
		///	scale pivot translate Y attribute
		static MObject scalePivotTranslateY;
		///	scale pivot translate Z attribute
		static MObject scalePivotTranslateZ;
	///Rotate orientation attribute
	static MObject rotateAxis;
		///	rotate orientation X attribute
		static MObject rotateAxisX;
		///	rotate orientation Y attribute
		static MObject rotateAxisY;
		///	rotate orientation Z attribute
		static MObject rotateAxisZ;		
	///	translate minus rotate pivot attribute
	static MObject transMinusRotatePivot;
		///	translateX minus rotate pivotX attribute
		static MObject transMinusRotatePivotX;
		///	translateY minus rotate pivotY attribute
		static MObject transMinusRotatePivotY;
		///	translateZ minus rotate pivotZ attribute
		static MObject transMinusRotatePivotZ;		

	///Minumum translation limits attribute
	static MObject minTransLimit;
		///Minimum translate X limit attribute
		static MObject minTransXLimit;
		///Minimum translate Y limit attribute
		static MObject minTransYLimit;
		///Minimum translate Z limit attribute
		static MObject minTransZLimit;
	///Maximum translation limits attribute
	static MObject maxTransLimit;
		///Maximum translate X limit attribute
		static MObject maxTransXLimit;
		///Maximum translate Y limit attribute
		static MObject maxTransYLimit;
		///Maximum translate Z limit attribute
		static MObject maxTransZLimit;
	///Enable the mimimum translation limits attribute 
	static MObject minTransLimitEnable;
		///Enable the minimum translate X limit attribute
		static MObject minTransXLimitEnable;
		///Enable the minimum translate Y limit attribute
		static MObject minTransYLimitEnable;
		///Enable the minimum translate Z limit attribute
		static MObject minTransZLimitEnable;
	///Enable the maximum translation limits attribute
	static MObject maxTransLimitEnable;
		///Enable the maximum translate X limit attribute
		static MObject maxTransXLimitEnable;
		///Enable the maximum translate Y limit attribute
		static MObject maxTransYLimitEnable;
		///Enable the maximum translate Z limit attribute
		static MObject maxTransZLimitEnable;
	///Minimum rotation limits attribute
	static MObject minRotLimit;
		///Minimum rotate X limit attribute
		static MObject minRotXLimit;
		///Minimum rotate Y limit attribute
		static MObject minRotYLimit;
		///Minimum rotate Z limit attribute
		static MObject minRotZLimit;
	///Maximum rotation limits attribute
	static MObject maxRotLimit;
		///Maximum rotate X limit attribute
		static MObject maxRotXLimit;
		///Maximum rotate Y limit attribute
		static MObject maxRotYLimit;
		///Maximum rotate Z limit attribute
		static MObject maxRotZLimit;
	///Enable minimum rotation limits attribute
	static MObject minRotLimitEnable;
		///Enable minimum rotate X limit attribute
		static MObject minRotXLimitEnable;
		///Enable minimum rotate Y limit attribute
		static MObject minRotYLimitEnable;
		///Enable minimum rotate Z limit attribute
		static MObject minRotZLimitEnable;
	///Enable maximum rotation limits attribute
	static MObject maxRotLimitEnable;
		///Enable maximum rotate X limit attribute
		static MObject maxRotXLimitEnable;
		///Enable maximum rotate Y limit attribute
		static MObject maxRotYLimitEnable;
		///Enable maximum rotate Z limit attribute
		static MObject maxRotZLimitEnable;
	///Minimum scale limit attribute
	static MObject minScaleLimit;
		///Minimum scale X limit attribute
		static MObject minScaleXLimit;
		///Minimum scale Y limit attribute
		static MObject minScaleYLimit;
		///Minimum scale Z limit attribute
		static MObject minScaleZLimit;
	///Maximum scale limit attribute
	static MObject maxScaleLimit;
		///Maximum scale X limit attribute
		static MObject maxScaleXLimit;
		///Maximum scale Y limit attribute
		static MObject maxScaleYLimit;
		///Maximum scale Z limit attribute
		static MObject maxScaleZLimit;
	///Enable minimum scale limit attribute
	static MObject minScaleLimitEnable;
		///Enable minimum scale X limit attribute
		static MObject minScaleXLimitEnable;
		///Enable minimum scale Y limit attribute
		static MObject minScaleYLimitEnable;
		///Enable minimum scale Z limit attribute
		static MObject minScaleZLimitEnable;
	///Enable aximum scale limit attribute
	static MObject maxScaleLimitEnable;
		///Enable maximum scale X limit attribute
		static MObject maxScaleXLimitEnable;
		///Enable maximum scale Y limit attribute
		static MObject maxScaleYLimitEnable;
		///Enable maximum scale Z limit attribute
		static MObject maxScaleZLimitEnable;
	///
	static MObject geometry;
	///
	static MObject xformMatrix;
	///
	static MObject selectHandle;
		///
		static MObject selectHandleX;
		///
		static MObject selectHandleY;
		///
		static MObject selectHandleZ;
	///
	static MObject inheritsTransform;
	///
	static MObject displayHandle;
	///
	static MObject displayScalePivot;
	///
	static MObject displayRotatePivot;
	///
	static MObject displayLocalAxis;
	///
	static MObject dynamics;
	///
	static MObject showManipDefault;
	///
	static MObject specifiedManipLocation;
	///
	static MObject rotateQuaternion;
		///
		static MObject rotateQuaternionX;
		///
		static MObject rotateQuaternionY;
		///
		static MObject rotateQuaternionZ;
		///
		static MObject rotateQuaternionW;
	///
	static MObject rotationInterpolation;
protected:
	//	Use this for the data.
	//
	MPxTransformationMatrix	*baseTransformationMatrix;

private:
	static void				initialSetup();
	static const char*	    className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxTransform */
