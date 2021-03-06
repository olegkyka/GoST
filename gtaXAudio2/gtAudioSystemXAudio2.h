#pragma once
#ifndef __GT_AUDIO_SYSTEM_XAUDIO2_H__
#define __GT_AUDIO_SYSTEM_XAUDIO2_H__


namespace gost{

	class gtAudioSystemXAudio2_7 : public gtAudioSystem{

		XAudioVersion			m_version;

		HMODULE					m_libXAudio;

		IXAudio2*				m_XAudio2;
		IXAudio2MasteringVoice* m_MasteringVoice;
		IUnknown*				m_ReverbEffect;
		IXAudio2SubmixVoice*	m_SubmixVoice;

		XAUDIO2FX_REVERB_I3DL2_PARAMETERS m_PRESET_PARAMS[ 30 ] ={
			XAUDIO2FX_I3DL2_PRESET_FOREST,
			XAUDIO2FX_I3DL2_PRESET_DEFAULT,
			XAUDIO2FX_I3DL2_PRESET_GENERIC,
			XAUDIO2FX_I3DL2_PRESET_PADDEDCELL,
			XAUDIO2FX_I3DL2_PRESET_ROOM,
			XAUDIO2FX_I3DL2_PRESET_BATHROOM,
			XAUDIO2FX_I3DL2_PRESET_LIVINGROOM,
			XAUDIO2FX_I3DL2_PRESET_STONEROOM,
			XAUDIO2FX_I3DL2_PRESET_AUDITORIUM,
			XAUDIO2FX_I3DL2_PRESET_CONCERTHALL,
			XAUDIO2FX_I3DL2_PRESET_CAVE,
			XAUDIO2FX_I3DL2_PRESET_ARENA,
			XAUDIO2FX_I3DL2_PRESET_HANGAR,
			XAUDIO2FX_I3DL2_PRESET_CARPETEDHALLWAY,
			XAUDIO2FX_I3DL2_PRESET_HALLWAY,
			XAUDIO2FX_I3DL2_PRESET_STONECORRIDOR,
			XAUDIO2FX_I3DL2_PRESET_ALLEY,
			XAUDIO2FX_I3DL2_PRESET_CITY,
			XAUDIO2FX_I3DL2_PRESET_MOUNTAINS,
			XAUDIO2FX_I3DL2_PRESET_QUARRY,
			XAUDIO2FX_I3DL2_PRESET_PLAIN,
			XAUDIO2FX_I3DL2_PRESET_PARKINGLOT,
			XAUDIO2FX_I3DL2_PRESET_SEWERPIPE,
			XAUDIO2FX_I3DL2_PRESET_UNDERWATER,
			XAUDIO2FX_I3DL2_PRESET_SMALLROOM,
			XAUDIO2FX_I3DL2_PRESET_MEDIUMROOM,
			XAUDIO2FX_I3DL2_PRESET_LARGEROOM,
			XAUDIO2FX_I3DL2_PRESET_MEDIUMHALL,
			XAUDIO2FX_I3DL2_PRESET_LARGEHALL,
			XAUDIO2FX_I3DL2_PRESET_PLATE,
		};

	public:

		gtAudioSystemXAudio2_7( void );
		~gtAudioSystemXAudio2_7( void );


	
		bool initialize( XAudioVersion version );


		class gtAudioObjectImpl : public gtAudioObjectCommon{
			gtAudioSource*					m_source;
			gtAudioSourceImpl*				m_sourceImpl;
			gtArray<IXAudio2SourceVoice*>	m_sourceVoice;

			f32								m_volume;

			u32								m_sourceMax;
			u32								m_currentSourceVoice;
			u32								m_numOfPlayedSounds;
			VoiceCallback					m_callback;
		public:

			gtAudioObjectImpl( gtAudioSource * );
			~gtAudioObjectImpl( void );

			void			play( void );
			void			pause( void );
			void			stop( void );
			void			setVolume( f32 volume );
			f32				getVolume( void );
			void			setLoop( bool isLoop );
			void			setAudioSource( gtAudioSource* source );
			gtAudioSource*	getAudioSource( void );

			void			updateBuffer( void );
			bool			init( u32 sp );

			void			setTime( f64 t );
		};

		class gtAudioStreamImpl : public gtAudioStream{
			bool					m_isOpen;
		//	gtFile *				m_file;
			f32						m_volume;
			StreamingVoiceContext	m_voiceContext;
			IXAudio2SourceVoice*	m_sourceVoice;

			Wave					m_wave;
			Ogg						m_ogg;

			gtAudioSourceInfo		m_info;


			IXAudio2*				m_device;

			AudioFileFormat			m_format;
		public:

			gtAudioStreamImpl( IXAudio2* d );
			~gtAudioStreamImpl( void );

			void			play( void );
			void			pause( void );
			void			stop( void );
			void			setVolume( f32 volume );
			f32				getVolume( void );
			void			setLoop( bool isLoop );
			void			setAudioSource( gtAudioSource* source );
			gtAudioSource*	getAudioSource( void );

			bool	close( void );
			bool	open( const gtString& fileName );
			void	setPlaybackPosition( f32 position );
			f32		getPlaybackPosition( void );


			bool	init( const gtString& fileName );

			bool isOgg( void ){ return m_format == AudioFileFormat::ogg; }
		};

		gtAudioObject*	createAudioObject( const gtString& fileName, u32 sp = 1u );
		gtAudioObject*	createAudioObject( gtAudioSource* source, u32 sp = 1u );

		gtAudioSource*	loadAudioSource( const gtString& fileName );

		bool	checkFeature( gtAudioPluginFeatures feature );
		u32		getSupportedExtensions( void );
		const s8*		getSupportedExtension( u32 id );

		gtAudioStream*	createStream( const gtString& fileName );

		static gtAudioSystemXAudio2_7* s_instance;
		static gtAudioSystemXAudio2_7*	getInstance( void );
	};

}

#endif

