#include "common.h"

gtModelImpl::gtModelImpl( u32 s, gtVertexType* ta ):
	m_stride( s )
{
	u32 sz = 0u;
	gtVertexType * vt = &ta[ 0u ];
	while( *vt++ != gtVertexType::end ) sz++;

	m_typeArray = new gtVertexType[ sz + 1u ];

	memcpy( m_typeArray, ta, (sz + 1u) * sizeof(gtVertexType) );

}

gtModelImpl::~gtModelImpl(){

	auto sz = m_submodels.size();
	for( u32 i = 0u; i < sz; ++i ){
		delete m_submodels[ i ];
	}

	if( m_typeArray )
		delete []m_typeArray;
}


gtSubModel*	gtModelImpl::createSubModel( u32 v_count, u32 i_count, u32 stride ){
	gtSubModel* subModel = new gtSubModel;
	
	if( !subModel ) return nullptr;

	subModel->m_iCount = i_count;
	subModel->m_vCount = v_count;
	
	subModel->allocate( stride );
	
	if( !subModel->m_vertices ){
		delete subModel;
		return nullptr;
	}

	return subModel;
}

	//	��������� ��� ������
gtSubModel*	gtModelImpl::addSubModel( u32 v_count, u32 i_count, u32 s ){
	
	gtSubModel* subModel = createSubModel( v_count, i_count, s );
	
	if( subModel )
		m_submodels.push_back( subModel );

	return subModel;
}

	//	������� ����� ��� ������ (�������, � ���������� ������)
gtSubModel*	gtModelImpl::addSubModel( gtSubModel* s ){

	gtSubModel* subModel = createSubModel( s->m_vCount, s->m_iCount, s->m_stride );
	
	if( subModel ){

		memcpy( subModel->m_vertices, s->m_vertices, subModel->m_vCount * subModel->m_stride );
		memcpy( subModel->m_indices, s->m_indices, subModel->m_iCount * sizeof( u16 ) );

		subModel->m_box = s->m_box;
		subModel->m_material = s->m_material;
		subModel->m_name = s->m_name;
		

		m_submodels.push_back( subModel );
	}

	return subModel;
}

	// ����� ��������� ���������� ��� �������
gtSubModel*	gtModelImpl::getSubModel( u32 id ){
	return m_submodels[id];
}

	//	������ ���������� �����������/����������
u32		gtModelImpl::getSubmodelsCount( void ){
	return m_submodels.size();
}

	//	������� ���������� ���� �� �������
u32		gtModelImpl::getStride( void ){
	return m_stride;
}

	//	������� �� ������ gtVertexType, ������� ������ ������������� gtVertexType::end
gtVertexType*	gtModelImpl::getTypeArray( void ){
	return &m_typeArray[0u];
}

	//	������ ���������� �������
const gtAabb&	gtModelImpl::getAabb( void ){
	return m_box;
}

	//	��������� ���������� �������
void			gtModelImpl::setAabb( const gtAabb& box ){
	m_box = box;
}

	//	�������� Aabb ���� ���������� � �� �� ������
	//	�������� Aabb ����� ������
void			gtModelImpl::updateAabb( void ){
	u32 sz = m_submodels.size();
	if( sz ){

		m_box.reset();

//		for each( auto * var in m_submodels ){
//			var->updateAabb();
//			m_box.add( var->m_box );
//		}

	}
}