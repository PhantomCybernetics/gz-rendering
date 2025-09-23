/*
 * Copyright (C) 2021 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef GZ_RENDERING_BASE_BASEBOUNDINGBOXCAMERA_HH_
#define GZ_RENDERING_BASE_BASEBOUNDINGBOXCAMERA_HH_

#include <vector>

#include <gz/common/Event.hh>
#include <gz/math/Color.hh>

#include "gz/rendering/base/BaseCamera.hh"
#include "gz/rendering/BoundingBoxCamera.hh"

namespace gz
{
  namespace rendering
  {
    inline namespace GZ_RENDERING_VERSION_NAMESPACE {

    template <class T>
    class BaseBoundingBoxCamera:
      public virtual BoundingBoxCamera,
      public virtual BaseCamera<T>,
      public virtual T
    {
      /// \brief Constructor
      protected: BaseBoundingBoxCamera();

      /// \brief Destructor
      public: virtual ~BaseBoundingBoxCamera();

      // Documentation inherited
      public: virtual const std::vector<BoundingBox> &BoundingBoxData2d() const;
      public: virtual const std::vector<BoundingBox> &BoundingBoxData3d() const;

      // Documentation inherited
      public: virtual gz::common::ConnectionPtr ConnectNewBoundingBoxes2D(
        std::function<void(const std::vector<BoundingBox> &)> _subscriber) = 0;

      public: virtual gz::common::ConnectionPtr ConnectNewBoundingBoxes3D(
        std::function<void(const std::vector<BoundingBox> &)> _subscriber) = 0;

      // Documentation inherited
      public: virtual void SetBoundingBoxType(BoundingBoxType _type2d, BoundingBoxType _type3d);

      // Documentation inherited
      public: virtual BoundingBoxType Type2d() const;
      public: virtual BoundingBoxType Type3d() const;

      // Documentation inherited
      public: virtual void DrawBoundingBox(unsigned char *_data,
        const math::Color &_color, const BoundingBox &_box) const = 0;

      /// \brief The bounding box type
      protected: BoundingBoxType type2d = BoundingBoxType::BBT_FULLBOX2D;
      protected: BoundingBoxType type3d = BoundingBoxType::BBT_BOX3D;

      /// \brief The bounding box data
      protected: std::vector<BoundingBox> boundingBoxes2d;
      protected: std::vector<BoundingBox> boundingBoxes3d;
    };

    //////////////////////////////////////////////////
    template <class T>
    BaseBoundingBoxCamera<T>::BaseBoundingBoxCamera()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseBoundingBoxCamera<T>::~BaseBoundingBoxCamera()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    const std::vector<BoundingBox> &
    BaseBoundingBoxCamera<T>::BoundingBoxData2d() const
    {
      return this->boundingBoxes2d;
    }

    //////////////////////////////////////////////////
    template <class T>
    const std::vector<BoundingBox> &
    BaseBoundingBoxCamera<T>::BoundingBoxData3d() const
    {
      return this->boundingBoxes3d;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseBoundingBoxCamera<T>::SetBoundingBoxType(BoundingBoxType _type2d, BoundingBoxType _type3d)
    {
      this->type2d = _type2d;
      this->type3d = _type3d;
    }

    //////////////////////////////////////////////////
    template <class T>
    BoundingBoxType BaseBoundingBoxCamera<T>::Type2d() const
    {
      return this->type2d;
    }

    //////////////////////////////////////////////////
    template <class T>
    BoundingBoxType BaseBoundingBoxCamera<T>::Type3d() const
    {
      return this->type3d;
    }
    }
  }
}
#endif
