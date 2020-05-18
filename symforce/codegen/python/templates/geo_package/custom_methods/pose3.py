    # --------------------------------------------------------------------------
    # Handwritten methods for Pose3
    # These will get included into the autogenerated class header.
    # --------------------------------------------------------------------------

    def __init__(self, R=None, t=None):
        rotation = R if R is not None else Rot3()
        position = t if R is not None else [0., 0., 0.]
        assert isinstance(rotation, Rot3)

        self.data = rotation.to_storage() + list(position)

    def rotation(self):
        return Rot3.from_storage(self.data[0:4])

    def position(self):
        return np.array(self.data[4:7])
