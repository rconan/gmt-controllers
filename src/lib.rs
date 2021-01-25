pub mod mount;

pub trait Simulink {
    fn initialize(&mut self);
    fn step(&self);
    fn terminate(&self);
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
