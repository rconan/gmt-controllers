//! # M1 center segment actuators controller
//!
//! The control system converts forces and moments at the segment
//! center of gravity into actuators forces in addition to any
//! offset actuators forces
//!
//! This is imported from a Simulink model converted into C code.

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(improper_ctypes)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

include!(concat!(env!("OUT_DIR"), "/controller.rs"));
