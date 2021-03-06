#pragma once
#ifndef __GT_CAMERA_IMPL_H__
#define __GT_CAMERA_IMPL_H__

namespace gost{

	class gtCameraImpl : public gtCamera{

		gtMatrix4		m_viewMatrix;
		gtMatrix4		m_rotationMatrix;
		gtMatrix4		m_projectionMatrix;

		v4f				m_viewPort;

		v3f				m_target;
		v3f				m_up;

		f32				m_fov;
		f32				m_near, m_far;
		f32				m_aspect;

		gtObjectType	m_type;
		gtCameraType	m_cameraType;
		
		gtCameraFrustum m_frustum;


		void			calculateFrustum( void );

	public:

		gtCameraImpl( void );
		~gtCameraImpl( void );

		gtCameraFrustum* getFrustum( void );


		//	=================================					gtGameObject
			//	��������� ��� �������
		gtObjectType		getType( void );
		
			//	������� ���������� � �������/��������/��������
		void				update( void );

			//	�������� ������ (���� �� �������� (�������� �� 3D �����))
		void				render( void );
		
		//	====================================				gtCamera
			//	������ ��� ������
		 gtCameraType		getCameraType( void );

		 	//	��������� ��� ������
		void				setCameraType( gtCameraType type );

			//	������ ������� �������
		 const gtMatrix4&	getViewMatrix( void );

			//	������ ������������ ������
		 const gtMatrix4&	getProjectionMatrix( void );

			//	������ ���� ���� ��� look at ������
		 const v3f&			getTarget( void );

			//	��������� ���� ���� ��� look at ������
		 void				setTarget( const v3f& );

		 	//	������ up ������ look at ������
		const v3f&			getUpVector( void );

			//	��������� up ������ look at ������
		void				setUpVector( const v3f& );

			//	��������� ������� ������� � ������� ���������� ���������
		 void				setNear( f32 );

			//	��������� ������� ������� ����� ������� ��������� �������������
		 void				setFar( f32 );

			//	��������� ����������� ������ (����. aspect = 800 : 600 )
		 void				setAspect( f32 );

			//	��������� ���� ������ (field of view)
		 void				setFOV( f32 );

			//	������ ������� ������� � ������� ���������� ���������
		 f32					getNear( void );

			//	������ ������� ������� ����� ������� ��������� �������������
		f32					getFar( void );

			//	������ ����������� ������
		f32					getAspect( void );

			//	������ ���� ������ (field of view)
		f32					getFOV( void );

		void					setViewPort( const v4f& v );
		 	//	��� ��������� ����� �����(2D ������), ��������� ���
		//void					setZoom( f32 v );

		gtAabb*				getAabb( void );
		gtObb*				getObb( void );
	};

}

#endif

