//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "Material.h"
#include "RankTwoTensor.h"

/// RankTwoDirectionalComponent computes the component of a rank-2 tensor in specified direction
class RankTwoDirectionalComponent : public Material
{
public:
  static InputParameters validParams();

  RankTwoDirectionalComponent(const InputParameters & parameters);

protected:
  virtual void initQpStatefulProperties() override;
  virtual void computeQpProperties() override;

  const MaterialProperty<RankTwoTensor> & _tensor;

  /// Name of the stress/strain to be calculated
  const std::string _property_name;

  /// Stress/strain value returned from calculation
  MaterialProperty<Real> & _property;

  /// The direction vector in which the scalar stress value is calculated
  const Point _direction;
};