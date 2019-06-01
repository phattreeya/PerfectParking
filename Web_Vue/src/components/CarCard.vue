<template>
  <div v-if="data !== null" class="car-card col-4 p-1">
    <div :class="['row wrapper', {'isOff': offClass}]">
      <div class="col-4">
        <img class="w-100" :src="image" alt="">
      </div>
      <div class="col-8 center">
        <p>
          {{ name }} is 
          <b v-if="data.DurationTime <= 0">Available</b>
          <b v-else>Unavailable</b>
        </p>
      </div>

      <div v-if="data.DurationTime != 0" class="col-12 center time">
          Time : {{ data.DurationTime }}
      </div>
      <div v-else class="col-12 center time">
          Time : {{ data.TotalTime }}
      </div>
    </div>
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'CarCard',
  props: ['name', 'path', 'image'],
  data () {
    return {
      data: null
    }
  },
  mounted () {
    let data = database().ref(this.path)
    let self = this
    data.on('value', function(snapshot) {
      self.data = snapshot.val()
      self.$emit('isParked', self.path, self.data.DurationTime <= 0 ? false : true)
    })
  },
  methods: {
    push () {
      console.log('Push!')
      if (this.data == true) {
        database().ref(this.path).set(false)
      } else {
        database().ref(this.path).set(true)
      }
    }
  },
  computed: {
    offClass () {
      if (this.data.DurationTime <= 0) return false
      else return true
    }
  }
}
</script>

<style lang="scss" scoped>
.car-card {
    box-shadow: 0 3px 6px rgba(0,0,0,0.16), 0 3px 6px rgba(0,0,0,0.23);
  .wrapper {
    padding: 10px 3px;
    background: rgb(71, 255, 111);
    margin: 1px;
  }
  p{
    margin-bottom: 60%;
    margin-top: 60%;
    font-size:1.6em; 
  }
}
.center {
  display: flex;
  justify-content: center;
  align-items: center;
}
.isOff {
  background: #fc3c3c!important;
  color: rgb(0, 0, 0);

}
img{
   margin-bottom: 100%;
   margin-top: 100%; 
}
.time{
    font-size: 2em;
    color: black;
}
</style>

